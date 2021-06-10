#pragma once


#include "antlr4-runtime.h"
#include "FooParserVisitor.h"


/**
 * This class provides an empty implementation of FooParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FooParserBaseVisitor : public FooParserVisitor {
public:

  virtual antlrcpp::Any visitStatements(FooParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(FooParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBody(FooParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBodyStatement(FooParser::BodyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(FooParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditionExpression(FooParser::AdditionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicationExpression(FooParser::MultiplicationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectationExpression(FooParser::AffectationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCallExpression(FooParser::FunctionCallExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(FooParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(FooParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(FooParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(FooParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(FooParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(FooParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

