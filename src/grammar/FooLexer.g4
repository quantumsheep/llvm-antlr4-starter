lexer grammar FooLexer;

Let: 'let';

Add: '+';
Mul: '*';
Equal: '=';

Print: 'print';

LeftParen: '(';
RightParen: ')';
LeftBracket: '{';
RightBracket: '}';
Comma: ',';

Semicolon: ';';

FunctionKeyworkd: 'fn';

FunctionTyper: '->';
Typei32: 'i32';
Return: 'return';

Name: [a-zA-Z_][a-zA-Z0-9_]*;
Number: [1-9][0-9]* | '0';

WhiteSpace: [ \t]+ -> skip;
LineTerminator: [\r\n] -> channel(HIDDEN);
