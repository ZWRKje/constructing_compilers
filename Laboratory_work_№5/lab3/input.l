%option noyywrap yylineno
%{
#include "TNode.h"
#define YYSTYPE TNode*
#include <stdlib.h>
#include "y.tab.h"
extern int yylex(void);
extern void yyerror(char* s);

%}

digit[0-9]+
ws[ \t\n]
region[A-Z]+
seprate[:]

%%
{digit} {
		if(!yylval) {
			printf("Syntax error \n");
			return ENDOF;
		}
		if(yylval->setVal(atoi(yytext)) == -1)	{
			printf("Syntax error \n");
			return ENDOF;
		};
		return NUM;
		}
{ws}	{return ENDOF;		}
{region} {
			yylval = new TNode();
			yylval->setName(yytext);
			return NAME;
		}
{seprate}	{
			return	SKIP;
			} 
\{		{return BEGINMARKER;}
\}		{return ENDMARKER;	}
,		{}


%%
