#include "FooParserVisitor.h"

#include "FooParser.h"


using namespace antlrcpp;
using namespace antlr4;

FooParser::FooParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FooParser::~FooParser() {
  delete _interpreter;
}

std::string FooParser::getGrammarFileName() const {
  return "FooParser.g4";
}

const std::vector<std::string>& FooParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FooParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StatementsContext ------------------------------------------------------------------

FooParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FooParser::StatementContext *> FooParser::StatementsContext::statement() {
  return getRuleContexts<FooParser::StatementContext>();
}

FooParser::StatementContext* FooParser::StatementsContext::statement(size_t i) {
  return getRuleContext<FooParser::StatementContext>(i);
}


size_t FooParser::StatementsContext::getRuleIndex() const {
  return FooParser::RuleStatements;
}


antlrcpp::Any FooParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

FooParser::StatementsContext* FooParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 0, FooParser::RuleStatements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FooParser::FunctionKeyworkd) {
      setState(22);
      statement();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

FooParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FooParser::FunctionContext* FooParser::StatementContext::function() {
  return getRuleContext<FooParser::FunctionContext>(0);
}


size_t FooParser::StatementContext::getRuleIndex() const {
  return FooParser::RuleStatement;
}


antlrcpp::Any FooParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

FooParser::StatementContext* FooParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, FooParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    function();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

FooParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::BodyContext::LeftBracket() {
  return getToken(FooParser::LeftBracket, 0);
}

tree::TerminalNode* FooParser::BodyContext::RightBracket() {
  return getToken(FooParser::RightBracket, 0);
}

std::vector<FooParser::BodyStatementContext *> FooParser::BodyContext::bodyStatement() {
  return getRuleContexts<FooParser::BodyStatementContext>();
}

FooParser::BodyStatementContext* FooParser::BodyContext::bodyStatement(size_t i) {
  return getRuleContext<FooParser::BodyStatementContext>(i);
}


size_t FooParser::BodyContext::getRuleIndex() const {
  return FooParser::RuleBody;
}


antlrcpp::Any FooParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

FooParser::BodyContext* FooParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, FooParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(FooParser::LeftBracket);
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FooParser::Let)
      | (1ULL << FooParser::Print)
      | (1ULL << FooParser::Return)
      | (1ULL << FooParser::Name)
      | (1ULL << FooParser::Number))) != 0)) {
      setState(31);
      bodyStatement();
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(37);
    match(FooParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyStatementContext ------------------------------------------------------------------

FooParser::BodyStatementContext::BodyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::BodyStatementContext::Semicolon() {
  return getToken(FooParser::Semicolon, 0);
}

FooParser::DeclarationContext* FooParser::BodyStatementContext::declaration() {
  return getRuleContext<FooParser::DeclarationContext>(0);
}

FooParser::ExpressionContext* FooParser::BodyStatementContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}

FooParser::PrintContext* FooParser::BodyStatementContext::print() {
  return getRuleContext<FooParser::PrintContext>(0);
}

FooParser::ReturnStatementContext* FooParser::BodyStatementContext::returnStatement() {
  return getRuleContext<FooParser::ReturnStatementContext>(0);
}


size_t FooParser::BodyStatementContext::getRuleIndex() const {
  return FooParser::RuleBodyStatement;
}


antlrcpp::Any FooParser::BodyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitBodyStatement(this);
  else
    return visitor->visitChildren(this);
}

FooParser::BodyStatementContext* FooParser::bodyStatement() {
  BodyStatementContext *_localctx = _tracker.createInstance<BodyStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, FooParser::RuleBodyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FooParser::Let: {
        setState(39);
        declaration();
        break;
      }

      case FooParser::Name:
      case FooParser::Number: {
        setState(40);
        expression(0);
        break;
      }

      case FooParser::Print: {
        setState(41);
        print();
        break;
      }

      case FooParser::Return: {
        setState(42);
        returnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(45);
    match(FooParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

FooParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::DeclarationContext::Let() {
  return getToken(FooParser::Let, 0);
}

tree::TerminalNode* FooParser::DeclarationContext::Name() {
  return getToken(FooParser::Name, 0);
}

tree::TerminalNode* FooParser::DeclarationContext::Equal() {
  return getToken(FooParser::Equal, 0);
}

FooParser::ExpressionContext* FooParser::DeclarationContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}


size_t FooParser::DeclarationContext::getRuleIndex() const {
  return FooParser::RuleDeclaration;
}


antlrcpp::Any FooParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

FooParser::DeclarationContext* FooParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, FooParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(FooParser::Let);
    setState(48);
    match(FooParser::Name);
    setState(49);
    match(FooParser::Equal);
    setState(50);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

FooParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FooParser::ExpressionContext::getRuleIndex() const {
  return FooParser::RuleExpression;
}

void FooParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::NumberLiteralExpressionContext::Number() {
  return getToken(FooParser::Number, 0);
}

FooParser::NumberLiteralExpressionContext::NumberLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::NumberLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitNumberLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditionExpressionContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::AdditionExpressionContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::AdditionExpressionContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::AdditionExpressionContext::Add() {
  return getToken(FooParser::Add, 0);
}

FooParser::AdditionExpressionContext::AdditionExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::AdditionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitAdditionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicationExpressionContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::MultiplicationExpressionContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::MultiplicationExpressionContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::MultiplicationExpressionContext::Mul() {
  return getToken(FooParser::Mul, 0);
}

FooParser::MultiplicationExpressionContext::MultiplicationExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::MultiplicationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AffectationExpressionContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::AffectationExpressionContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::AffectationExpressionContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::AffectationExpressionContext::Equal() {
  return getToken(FooParser::Equal, 0);
}

FooParser::AffectationExpressionContext::AffectationExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::AffectationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitAffectationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::IdentifierExpressionContext::Name() {
  return getToken(FooParser::Name, 0);
}

FooParser::IdentifierExpressionContext::IdentifierExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
  else
    return visitor->visitChildren(this);
}

FooParser::ExpressionContext* FooParser::expression() {
   return expression(0);
}

FooParser::ExpressionContext* FooParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FooParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  FooParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, FooParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FooParser::Name: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(53);
        match(FooParser::Name);
        break;
      }

      case FooParser::Number: {
        _localctx = _tracker.createInstance<NumberLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(54);
        match(FooParser::Number);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(68);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(66);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(57);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(58);
          match(FooParser::Mul);
          setState(59);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditionExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(60);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(61);
          match(FooParser::Add);
          setState(62);
          expression(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AffectationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(63);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(64);
          match(FooParser::Equal);
          setState(65);
          expression(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(70);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

FooParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::PrintContext::Print() {
  return getToken(FooParser::Print, 0);
}

tree::TerminalNode* FooParser::PrintContext::LeftParen() {
  return getToken(FooParser::LeftParen, 0);
}

std::vector<FooParser::ExpressionContext *> FooParser::PrintContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::PrintContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::PrintContext::RightParen() {
  return getToken(FooParser::RightParen, 0);
}

std::vector<tree::TerminalNode *> FooParser::PrintContext::Comma() {
  return getTokens(FooParser::Comma);
}

tree::TerminalNode* FooParser::PrintContext::Comma(size_t i) {
  return getToken(FooParser::Comma, i);
}


size_t FooParser::PrintContext::getRuleIndex() const {
  return FooParser::RulePrint;
}


antlrcpp::Any FooParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

FooParser::PrintContext* FooParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 12, FooParser::RulePrint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(FooParser::Print);
    setState(72);
    match(FooParser::LeftParen);
    setState(73);
    expression(0);
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FooParser::Comma) {
      setState(74);
      match(FooParser::Comma);
      setState(75);
      expression(0);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(FooParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FooParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FooParser::FunctionDeclarationContext* FooParser::FunctionContext::functionDeclaration() {
  return getRuleContext<FooParser::FunctionDeclarationContext>(0);
}

FooParser::BodyContext* FooParser::FunctionContext::body() {
  return getRuleContext<FooParser::BodyContext>(0);
}


size_t FooParser::FunctionContext::getRuleIndex() const {
  return FooParser::RuleFunction;
}


antlrcpp::Any FooParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

FooParser::FunctionContext* FooParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 14, FooParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    functionDeclaration();
    setState(84);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

FooParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::FunctionDeclarationContext::FunctionKeyworkd() {
  return getToken(FooParser::FunctionKeyworkd, 0);
}

tree::TerminalNode* FooParser::FunctionDeclarationContext::Name() {
  return getToken(FooParser::Name, 0);
}

tree::TerminalNode* FooParser::FunctionDeclarationContext::LeftParen() {
  return getToken(FooParser::LeftParen, 0);
}

tree::TerminalNode* FooParser::FunctionDeclarationContext::RightParen() {
  return getToken(FooParser::RightParen, 0);
}

tree::TerminalNode* FooParser::FunctionDeclarationContext::FunctionTyper() {
  return getToken(FooParser::FunctionTyper, 0);
}

FooParser::TypeContext* FooParser::FunctionDeclarationContext::type() {
  return getRuleContext<FooParser::TypeContext>(0);
}


size_t FooParser::FunctionDeclarationContext::getRuleIndex() const {
  return FooParser::RuleFunctionDeclaration;
}


antlrcpp::Any FooParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

FooParser::FunctionDeclarationContext* FooParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, FooParser::RuleFunctionDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(FooParser::FunctionKeyworkd);
    setState(87);
    match(FooParser::Name);
    setState(88);
    match(FooParser::LeftParen);
    setState(89);
    match(FooParser::RightParen);
    setState(90);
    match(FooParser::FunctionTyper);
    setState(91);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

FooParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::ReturnStatementContext::Return() {
  return getToken(FooParser::Return, 0);
}

FooParser::ExpressionContext* FooParser::ReturnStatementContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}


size_t FooParser::ReturnStatementContext::getRuleIndex() const {
  return FooParser::RuleReturnStatement;
}


antlrcpp::Any FooParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

FooParser::ReturnStatementContext* FooParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, FooParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(FooParser::Return);
    setState(94);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FooParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::TypeContext::Typei32() {
  return getToken(FooParser::Typei32, 0);
}


size_t FooParser::TypeContext::getRuleIndex() const {
  return FooParser::RuleType;
}


antlrcpp::Any FooParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FooParser::TypeContext* FooParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 20, FooParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(FooParser::Typei32);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FooParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FooParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> FooParser::_decisionToDFA;
atn::PredictionContextCache FooParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FooParser::_atn;
std::vector<uint16_t> FooParser::_serializedATN;

std::vector<std::string> FooParser::_ruleNames = {
  "statements", "statement", "body", "bodyStatement", "declaration", "expression", 
  "print", "function", "functionDeclaration", "returnStatement", "type"
};

std::vector<std::string> FooParser::_literalNames = {
  "", "'let'", "'+'", "'*'", "'='", "'print'", "'('", "')'", "'{'", "'}'", 
  "','", "';'", "'fn'", "'->'", "'i32'", "'return'"
};

std::vector<std::string> FooParser::_symbolicNames = {
  "", "Let", "Add", "Mul", "Equal", "Print", "LeftParen", "RightParen", 
  "LeftBracket", "RightBracket", "Comma", "Semicolon", "FunctionKeyworkd", 
  "FunctionTyper", "Typei32", "Return", "Name", "Number", "WhiteSpace", 
  "LineTerminator"
};

dfa::Vocabulary FooParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FooParser::_tokenNames;

FooParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x15, 0x65, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x7, 0x2, 0x1a, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x23, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x26, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x2e, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x3a, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x45, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x48, 0xb, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4f, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x52, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x2, 0x3, 0xc, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x2, 0x2, 0x2, 0x63, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x20, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x31, 0x3, 0x2, 0x2, 0x2, 0xc, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x49, 0x3, 0x2, 0x2, 0x2, 0x10, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x58, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x62, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x10, 
    0x9, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x24, 0x7, 0xa, 0x2, 
    0x2, 0x21, 0x23, 0x5, 0x8, 0x5, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x26, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x27, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0xb, 0x2, 0x2, 0x28, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2e, 0x5, 0xa, 0x6, 0x2, 0x2a, 0x2e, 0x5, 0xc, 
    0x7, 0x2, 0x2b, 0x2e, 0x5, 0xe, 0x8, 0x2, 0x2c, 0x2e, 0x5, 0x14, 0xb, 
    0x2, 0x2d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xd, 0x2, 0x2, 0x30, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x33, 0x7, 
    0x12, 0x2, 0x2, 0x33, 0x34, 0x7, 0x6, 0x2, 0x2, 0x34, 0x35, 0x5, 0xc, 
    0x7, 0x2, 0x35, 0xb, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x8, 0x7, 0x1, 
    0x2, 0x37, 0x3a, 0x7, 0x12, 0x2, 0x2, 0x38, 0x3a, 0x7, 0x13, 0x2, 0x2, 
    0x39, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0xc, 0x7, 0x2, 0x2, 0x3c, 0x3d, 
    0x7, 0x5, 0x2, 0x2, 0x3d, 0x45, 0x5, 0xc, 0x7, 0x8, 0x3e, 0x3f, 0xc, 
    0x6, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x4, 0x2, 0x2, 0x40, 0x45, 0x5, 0xc, 
    0x7, 0x7, 0x41, 0x42, 0xc, 0x5, 0x2, 0x2, 0x42, 0x43, 0x7, 0x6, 0x2, 
    0x2, 0x43, 0x45, 0x5, 0xc, 0x7, 0x6, 0x44, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0xd, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x7, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x8, 
    0x2, 0x2, 0x4b, 0x50, 0x5, 0xc, 0x7, 0x2, 0x4c, 0x4d, 0x7, 0xc, 0x2, 
    0x2, 0x4d, 0x4f, 0x5, 0xc, 0x7, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x9, 0x2, 0x2, 0x54, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x56, 0x5, 0x12, 0xa, 0x2, 0x56, 0x57, 0x5, 0x6, 
    0x4, 0x2, 0x57, 0x11, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0xe, 0x2, 
    0x2, 0x59, 0x5a, 0x7, 0x12, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x8, 0x2, 0x2, 
    0x5b, 0x5c, 0x7, 0x9, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0xf, 0x2, 0x2, 0x5d, 
    0x5e, 0x5, 0x16, 0xc, 0x2, 0x5e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x7, 0x11, 0x2, 0x2, 0x60, 0x61, 0x5, 0xc, 0x7, 0x2, 0x61, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x10, 0x2, 0x2, 0x63, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x9, 0x1b, 0x24, 0x2d, 0x39, 0x44, 0x46, 0x50, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FooParser::Initializer FooParser::_init;
