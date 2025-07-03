%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
%}


%union {
    int num1;
    float num;
}

%token <num1> INT
%token <num> FLOAT
%type <num> E T F

%%
S : E {printf("\nResult: %f\n", $1);}
  ;

E : E '+' T { printf("+ "); $$ = $1 + $3; }
  | T
  ;

T : T '*' F { printf("* "); $$ = $1 * $3; }
  | F
  ;

F : '(' E ')' { $$ = $2; }
  | INT { printf("INT "); $$ = $1; }
  | FLOAT { printf("FLOAT "); $$ = $1; }
  ;
%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Compiler error: %s\n", s);
}
