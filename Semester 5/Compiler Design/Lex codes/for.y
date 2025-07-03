%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
%}

%token FOR WHILE DO REL ID NUM INC

%%

S : FOR '(' ASS ';' C ';' ASS ')' '{' S '}'               { printf("FOR statement matched\n"); }
  | WHILE '(' C ')' S         { printf("WHILE statement matched\n"); }
  | I '=' E ';'                  { printf("Assignment matched\n"); }
  ;

C : I REL I                      { printf("Condition matched\n"); }
  ;
  
ASS : I '=' E ';'		 { printf("Assignment amtched\n"); }
    | I INC
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
