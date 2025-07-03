%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    int num;
    char *id;
}

%token NUM ID
%type <num> NUM
%type <id> ID

%left '+'  
%left '*'  

%%
E : E '+' T     { printf("Addition\n"); }
  | T           ;

T : T '*' F     { printf("Multiplication\n"); }
  | F           ;

F : '(' E ')'   { printf("Parenthesized Expression\n"); }
  | NUM         { printf("Number: %d\n", $1); }
  | ID          { printf("Identifier: %s\n", $1); free($1); }
  ;
%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
int yywrap() {
    return 1;
}
