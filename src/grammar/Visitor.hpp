#pragma once

#include "exceptions/NotImplementedException.hpp"
#include "exceptions/SyntaxErrorException.hpp"
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

        auto functionReturnType = llvm::Type::getInt32Ty(builder.getContext());
        auto functionType = llvm::FunctionType::get(functionReturnType, {}, false);
        auto functionLinkage = llvm::GlobalValue::LinkageTypes::ExternalLinkage;

        auto function = llvm::Function::Create(functionType, functionLinkage, "main", *this->llvm_module);

        auto block = llvm::BasicBlock::Create(builder.getContext(), "entry", function);
        this->builder.SetInsertPoint(block);

        auto declarationContext = parser.declaration();

        if (lexer.getNumberOfSyntaxErrors() || parser.getNumberOfSyntaxErrors())
        {
            throw SyntaxErrorException();
        }

        auto alloca = this->visitDeclaration(declarationContext);

        auto load = builder.CreateLoad(alloca->getType()->getPointerElementType(), alloca);
        Helpers::printf(llvm_module, builder, "%d\n", {load});

        this->builder.CreateRet(llvm::ConstantInt::get(functionReturnType, 0, true));
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

        return this->builder.CreateMul(left, right);
    }

    llvm::Value *visitAdditionExpressionContext(FooParser::AdditionExpressionContext *context)
    {
        auto left = this->visitExpression(context->expression(0));
        auto right = this->visitExpression(context->expression(1));

        return this->builder.CreateAdd(left, right);
    }

    llvm::Value *visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *context)
    {
        auto str = context->getText();
        auto value = std::stol(str);

        auto type = llvm::Type::getInt64Ty(this->builder.getContext());

        return llvm::ConstantInt::get(type, value, true);
    }
};
} // namespace FooLang
