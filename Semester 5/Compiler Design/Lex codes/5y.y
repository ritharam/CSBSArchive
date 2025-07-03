%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
%}

%token NUM ID
%token LPAREN RPAREN SEMICOL
%token FOR WHILE DO
%token REL PLUS MINUS MUL DIV EQ
%token INC ADD_ASSIGN
%token LBRACE RBRACE

%%

s : FOR LPAREN assign SEMICOL C SEMICOL assign RPAREN S { printf("FOR loop\n"); }
  | WHILE LPAREN C RPAREN S { printf("WHILE loop\n"); }
  | DO S WHILE LPAREN C RPAREN SEMICOL { printf("DO-WHILE loop\n"); }
  | S
  ;

S : LBRACE Ss RBRACE { printf("Compound statement\n"); }
     | assign SEMICOL { printf("Assignment statement\n"); }
     | /* empty */
     ;

Ss : S
      | Ss S
      ;

assign : id EQ e { printf("= assignment\n"); }
       | id ADD_ASSIGN e { printf("+= assignment\n"); }
       | id INC { printf("Increment ++\n"); }
       ;

C : val REL val { printf("Conditional expression\n"); }
     ;

e : e PLUS t { printf("+ addition\n"); }
  | e MINUS t { printf("- subtraction\n"); }
  | t
  ;

t : t MUL f { printf("* multiplication\n"); }
  | t DIV f { printf("/ division\n"); }
  | f
  ;

f : LPAREN e RPAREN
  | val
  ;

val : id
    | NUM { printf("NUM\n"); }
    ;

id : ID { printf("ID\n"); }
   ;

%%

int main() {
    if (yyparse()) {
        printf("\nInvalid syntax\n");
    } else {
        printf("\nValid syntax\n");
    }
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Compiler error: %s\n", s);
}
