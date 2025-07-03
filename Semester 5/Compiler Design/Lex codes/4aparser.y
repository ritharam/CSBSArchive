/*%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char* s);
%}

%token NUMBER
%token VAR

%%
expr : expr '+' term { printf("plus "); }
     | expr '-' term { printf("minus "); }
     | term
     ;

term : term '*' factor { printf("times "); }
     | term '/' factor { printf("divide "); }
     | factor
     ;

factor : '(' expr ')'
       | VAR { printf("variable "); }
       | NUMBER { printf("number "); }
       ;

%%

int main() {
    printf("Enter expression:");
    if (yyparse() == 0) {
        printf("Parsing completed successfully!\n");
    }
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
*/

%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUMBER
%%
input:
| input line
;
line:
'\n'
| expr '\n' { printf("Result: %d\n", $1); }
;
expr:
NUMBER
| expr "+" expr { $$ = $1 + $3; }
;
%%
int main( ) {
printf("Enter an expression: ");
return yyparse();
}
void yyerror(const char *s) {
fprintf(stderr, "Error: %s\n", s);
}
