%{
#include <stdio.h>
#include "TNode.h"
#include <cctype>
#include <iostream>
#define YYSTYPE TNode*
int yylex(void);
void yyerror(const char* s);
TNode root;

%}

%token NUM
%token ENDOF
%token BEGINMARKER
%token ENDMARKER
%token NAME
%token SKIP
%%

input:
	| input line
	
line: ENDOF
	| S ENDOF					{root.addChild($1);
									printTree(root,0);}
	
S:	SMTH BEGINMARKER S ENDMARKER	{$$->addChild($3);}
	| S S 						{$$->addBrother($2);}
	| SMTH

SMTH: NAME SKIP NUM

%%

void yyerror(const char *s) {
	std::cout<< s;
}

int main() {
	return yyparse();
}