parser grammar FooParser;

options {
	tokenVocab = FooLexer;
}

statements: statement*;

statement: function;

body: '{' bodyStatement* '}';

bodyStatement: (
		declaration
		| expression
		| print
		| returnStatement
	) ';';

declaration: Let Name Equal expression;

expression:
	expression Mul expression	# MultiplicationExpression
	| expression Add expression	# AdditionExpression
	| expression '=' expression	# AffectationExpression
	| Name						# IdentifierExpression
	| Number					# NumberLiteralExpression;

print: 'print' '(' expression (',' expression)* ')';

function: functionDeclaration body;

functionDeclaration:
	FunctionKeyworkd Name '(' ')' FunctionTyper type;

returnStatement: 'return' expression;

type: 'i32';
