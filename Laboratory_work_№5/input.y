%{
 #include <stdio.h>
 extern FILE *yyin;
 extern int yylineno;
 extern int ch;
 extern char *yytext;
 int yylex(void);
 void yyerror(char *);
%}
%token  WHILE DONE ID NUMBER
%right ASSIGN
%left CMP
%%
program: statement { printf("\nprogram\n"); }
statement: WHILE'('expr_cmp')'oper DONE {
 printf("\nstatement\n");}
statement: error';'
oper:   statement { printf("\noperator\n"); }
        | expr { printf("\noperator\n"); }
        | statement oper { printf("\noperator\n"); }
expr:    ID ASSIGN expr_cmp ';'{ printf("\nassign\n"); }
        | ID ASSIGN expr_cmp ';' expr { printf("\nassign\n"); }
expr_cmp: prim_expr CMP prim_expr { printf("\ncomparison\n"); }
prim_expr: ID   { printf("\nprimary expression\n"); } 
            | NUMBER { printf("\nprimary expression\n"); }

%%
void yyerror(char *errmsg)
{
 fprintf(stderr, "%s (%d, %d): %s\n", errmsg, yylineno, ch, yytext);
}
int main(int argc, char **argv)
{
 if(argc < 2)
 {
 printf("\nNot enough arguments. Please specify filename. \n");
 return -1;
 }
 if((yyin = fopen(argv[1], "r")) == NULL)
 {
 printf("\nCannot open file %s.\n", argv[1]);
 return -1;
 }
 ch = 1;
 yylineno = 1;
 yyparse();
 return 0;
}
