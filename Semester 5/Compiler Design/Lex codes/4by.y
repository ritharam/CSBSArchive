%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
%}

%token IF ELSE ID REL NUM

%%

S : IF '(' C ')' S               { printf("IF statement matched\n"); }
  | IF '(' C ')' S ELSE S        { printf("IF-ELSE statement matched\n"); }
  | I '=' E ';'               { printf("Assignment matched\n"); }
  ;

C : I REL I                      { printf("Condition matched\n"); }
  ;

E : E '+' T                      { printf("Addition matched\n"); }
  | T
  ;

T : T '*' F                      { printf("Multiplication matched\n"); }
  | F
  ;

F : '(' E ')' 
  | I
  ;

I : ID                           { printf("Identifier matched\n"); }
  | NUM
  ;


%%

int main() {
    yyparse();
    printf("\n");
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Compiler error: %s\n", s);
}
