#pragma once


#include "antlr4-runtime.h"




class  FooLexer : public antlr4::Lexer {
public:
  enum {
    Let = 1, Add = 2, Mul = 3, Equal = 4, Print = 5, LeftParen = 6, RightParen = 7, 
    LeftBracket = 8, RightBracket = 9, Comma = 10, Semicolon = 11, FunctionKeyworkd = 12, 
    FunctionTyper = 13, Typei32 = 14, Return = 15, Name = 16, Number = 17, 
    WhiteSpace = 18, LineTerminator = 19
  };

  explicit FooLexer(antlr4::CharStream *input);
  ~FooLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

