// Parser for Arithmetic Expression 

%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER

%%

input:
    /* empty */
    | input line
    ;

line:
    '\n'
    | expr '\n' { printf("Result: %d\n", $1); }
    ;

expr:
    NUMBER
    | expr '+' expr { $$ = $1 + $3; }
    ;

%%

int main() {
    printf("Enter an expression: ");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
