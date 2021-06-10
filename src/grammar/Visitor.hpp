#pragma once

#include "exceptions/InvalidLeftHandAssignmentException.hpp"
#include "exceptions/NotCallableException.hpp"
#include "exceptions/NotImplementedException.hpp"
#include "exceptions/SyntaxErrorException.hpp"
#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/VariableNotFoundException.hpp"
#include "runtime/FooLexer.h"
#include "runtime/FooParserBaseVisitor.h"

#include "../logic/Helper.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include <logic/Scope.hpp>
#include <sstream>
#include <string>
#include <vector>

using namespace antlr4;

namespace FooLang
{
class ParserErrorListener : public BaseErrorListener
{
public:
    virtual void syntaxError(
        Recognizer *recognizer,
        Token *offendingSymbol,
        size_t line,
        size_t charPositionInLine,
        const std::string &msg,
        std::exception_ptr e) override
    {
        std::stringstream s;
        s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
        throw std::invalid_argument(s.str());
    }
};

class Visitor
{
public:
    std::unique_ptr<llvm::LLVMContext> llvm_context;
    std::unique_ptr<llvm::Module> llvm_module;
    llvm::IRBuilder<> builder;
    std::string path;

    std::map<std::string, llvm::Value *> variables;

    Visitor(const std::string &path) : llvm_context(std::make_unique<llvm::LLVMContext>()),
                                       llvm_module(std::make_unique<llvm::Module>(path, *this->llvm_context)),
                                       builder(*this->llvm_context),
                                       path(path) {}

    void start()
    {
        std::ifstream stream;
        stream.open(this->path);

        ANTLRInputStream input(stream);
        FooLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        FooParser parser(&tokens);

        auto statementsContext = parser.statements();

        for (auto &statement : statementsContext->statement())
        {
            if (lexer.getNumberOfSyntaxErrors() || parser.getNumberOfSyntaxErrors())
            {
                throw SyntaxErrorException();
            }

            this->visitStatement(statement);
        }
    }

    llvm::Value *loadIfAlloca(llvm::Value *value)
    {
        if (auto alloca = llvm::dyn_cast<llvm::AllocaInst>(value))
        {
            return this->builder.CreateLoad(alloca);
        }

        return value;
    }

    void visitStatement(FooParser::StatementContext *context)
    {
        if (auto functionContext = context->function())
        {
            this->visitFunction(functionContext);
        }
    }

    void visitFunction(FooParser::FunctionContext *context)
    {
        auto functionDeclaration = this->visitFunctionDeclaration(context->functionDeclaration());

        auto block = this->visitBody(context->body(), "entry", functionDeclaration);
    }

    llvm::Function *visitFunctionDeclaration(FooParser::FunctionDeclarationContext *context)
    {
        auto returnType = this->visitType(context->type());
        auto name = context->Name()->getText();

        auto functionType = llvm::FunctionType::get(returnType, {}, false);
        auto functionLinkage = name == "main" ? llvm::GlobalValue::LinkageTypes::ExternalLinkage : llvm::GlobalValue::LinkageTypes::LinkOnceAnyLinkage;

        auto function = llvm::Function::Create(functionType, functionLinkage, name, *llvm_module);

        variables[name] = function;
        return function;
    }

    llvm::Type *visitType(FooParser::TypeContext *context)
    {
        if (auto type = context->Typei32())
        {
            return llvm::Type::getInt32Ty(*llvm_context);
        }

        throw TypeNotFoundException(context->getText());
    }

    llvm::BasicBlock *visitBody(FooParser::BodyContext *context, const std::string &name = "", llvm::Function *function = nullptr)
    {
        auto block = llvm::BasicBlock::Create(*llvm_context, name);

        if (function != nullptr)
        {
            block->insertInto(function);
        }

        this->builder.SetInsertPoint(block);

        for (auto &statement : context->bodyStatement())
        {
            this->visitBodyStatement(statement);
        }

        return block;
    }

    void visitBodyStatement(FooParser::BodyStatementContext *context)
    {
        if (auto expressionContext = context->expression())
        {
            this->visitExpression(expressionContext);
        }
        else if (auto declarationContext = context->declaration())
        {
            this->visitDeclaration(declarationContext);
        }
        else if (auto printContext = context->print())
        {
            this->visitPrint(printContext);
        }
        else if (auto returnStatementContext = context->returnStatement())
        {
            this->visitReturnStatement(returnStatementContext);
        }
    }

    llvm::AllocaInst *visitDeclaration(FooParser::DeclarationContext *context)
    {
        auto name = context->Name()->getText();
        auto value = this->visitExpression(context->expression());
        auto type = value->getType();

        auto alloca = this->builder.CreateAlloca(type, nullptr, name);
        this->builder.CreateStore(value, alloca);

        variables[name] = alloca;

        return alloca;
    }

    llvm::Value *visitExpression(FooParser::ExpressionContext *context)
    {
        if (auto multiplicationExpressionContext = dynamic_cast<FooParser::MultiplicationExpressionContext *>(context))
        {
            return this->visitMultiplicationExpressionContext(multiplicationExpressionContext);
        }
        else if (auto additionExpressionContext = dynamic_cast<FooParser::AdditionExpressionContext *>(context))
        {
            return this->visitAdditionExpressionContext(additionExpressionContext);
        }
        else if (auto affectationExpressionContext = dynamic_cast<FooParser::AffectationExpressionContext *>(context))
        {
            return this->visitAffectationExpression(affectationExpressionContext);
        }
        else if (auto functionCallExpressionContext = dynamic_cast<FooParser::FunctionCallExpressionContext *>(context))
        {
            return this->visitFunctionCallExpression(functionCallExpressionContext);
        }
        else if (auto identifierExpressionContext = dynamic_cast<FooParser::IdentifierExpressionContext *>(context))
        {
            return this->visitIdentifierExpression(identifierExpressionContext);
        }
        else if (auto numberLiteralExpressionContext = dynamic_cast<FooParser::NumberLiteralExpressionContext *>(context))
        {
            return this->visitNumberLiteralExpression(numberLiteralExpressionContext);
        }

        throw NotImplementedException();
    }

    llvm::Value *visitMultiplicationExpressionContext(FooParser::MultiplicationExpressionContext *context)
    {
        auto left = this->visitExpression(context->expression(0));
        auto right = this->visitExpression(context->expression(1));

        return this->builder.CreateMul(loadIfAlloca(left), loadIfAlloca(right));
    }

    llvm::Value *visitAdditionExpressionContext(FooParser::AdditionExpressionContext *context)
    {
        auto left = this->visitExpression(context->expression(0));
        auto right = this->visitExpression(context->expression(1));

        return this->builder.CreateAdd(loadIfAlloca(left), loadIfAlloca(right));
    }

    llvm::AllocaInst *visitAffectationExpression(FooParser::AffectationExpressionContext *context)
    {
        auto alloca = this->visitExpression(context->expression(0));

        if (!llvm::dyn_cast<llvm::AllocaInst>(alloca))
        {
            throw InvalidLeftHandAssignmentException();
        }

        auto expression = loadIfAlloca(this->visitExpression(context->expression(1)));

        this->builder.CreateStore(expression, alloca);

        return reinterpret_cast<llvm::AllocaInst *>(alloca);
    }

    llvm::Value *visitFunctionCallExpression(FooParser::FunctionCallExpressionContext *context)
    {
        auto expression = loadIfAlloca(this->visitExpression(context->expression()));

        if (!expression->getType()->isPointerTy() && expression->getType()->getPointerElementType()->isFunctionTy())
        {
            throw NotCallableException(context->expression()->getText());
        }

        return this->builder.CreateCall(llvm::dyn_cast<llvm::FunctionType>(expression->getType()->getPointerElementType()), expression);
    }

    llvm::Value *visitIdentifierExpression(FooParser::IdentifierExpressionContext *context)
    {
        auto name = context->Name()->getText();
        auto it = variables.find(name);

        if (it == variables.end())
        {
            throw VariableNotFoundException(name);
        }

        return it->second;
    }

    llvm::Value *visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *context)
    {
        auto str = context->getText();
        auto value = std::stol(str);

        auto type = llvm::Type::getInt64Ty(this->builder.getContext());

        return llvm::ConstantInt::get(type, value, true);
    }

    void visitPrint(FooParser::PrintContext *context)
    {
        for (auto &expressionContext : context->expression())
        {
            auto expression = loadIfAlloca(this->visitExpression(expressionContext));

            if (expression->getType()->isIntegerTy())
            {
                Helpers::printf(llvm_module, builder, "%d ", {expression});
            }
        }

        Helpers::printf(llvm_module, builder, "\n");
    }

    void visitReturnStatement(FooParser::ReturnStatementContext *context)
    {
        auto expression = this->visitExpression(context->expression());
        this->builder.CreateRet(loadIfAlloca(expression));
    }
};
} // namespace FooLang
