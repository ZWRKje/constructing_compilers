%option noyywrap yylineno
%{
 #include "y.tab.h"
 #include <stdio.h>
 int ch;
 extern int yylex(void);
 extern void yyerror (char *);
%}
digit[0-9]
letter[a-zA-Z]
delim[();]
oper[<>=]
ws[ \t\n]
%%
while { ch += yyleng; return WHILE; }
done { ch += yyleng; return DONE; }
("_"|{letter})("_"|{letter}|{digit})* { ch += yyleng; 
        return ID; 
}
[-+]?({digit}*\.{digit}+|{digit}+\.|{digit}+)([eE][-+]?{digit}+)?[flFL]? { ch += yyleng;

 return NUMBER; }
{oper} { ch += yyleng; 
        return CMP;
 }
":=" { ch += yyleng; return ASSIGN; }
{delim} { ch += yyleng; 
        return *yytext; }
{ws}+ { ch += yyleng; }
. { yyerror("Unknown character"); ch += yyleng; }
%%