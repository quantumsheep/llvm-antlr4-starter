#pragma once


#include "antlr4-runtime.h"
#include "FooParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FooParser.
 */
class  FooParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FooParser.
   */
    virtual antlrcpp::Any visitStatements(FooParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(FooParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitBody(FooParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitBodyStatement(FooParser::BodyStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(FooParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditionExpression(FooParser::AdditionExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicationExpression(FooParser::MultiplicationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAffectationExpression(FooParser::AffectationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpression(FooParser::IdentifierExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrint(FooParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitFunction(FooParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(FooParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(FooParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitType(FooParser::TypeContext *context) = 0;


};

