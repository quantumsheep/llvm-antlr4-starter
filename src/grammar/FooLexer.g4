lexer grammar FooLexer;

ToImplement: 'to implement';

WhiteSpace: [ \t]+ -> skip;
LineTerminator: [\r\n] -> channel(HIDDEN);
