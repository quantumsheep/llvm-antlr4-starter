parser grammar FooParser;

options {
	tokenVocab = FooLexer;
}

instructions: instruction*;

instruction: ToImplement;
