%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
%}

%token STR NUM ID
%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOL
%token INT
%token IF ELSE
%token FOR WHILE DO
%token REL PLUS MINUS MUL DIV MOD EQ

%%

program : function_def
	| stmts
        ;

function_def : INT ID LPAREN param_list RPAREN LBRACE decls stmts RBRACE
            { printf("Function definition\n"); }
            ;

param_list :
            | param_list COMMA param
            | param
            ;

param : INT ID { printf("Parameter declaration\n"); }
      ;

decls : decls decl
      | decl
      ;

decl : INT ID SEMICOL { printf("Variable declaration\n"); }
     ;

stmts : stmts stmt
      | stmt
      ;

stmt : assign SEMICOL
     | expr SEMICOL
     ;

assign : id EQ expr { printf("Assignment\n"); }
       ;

expr : expr PLUS term { printf("+ addition\n"); }
     | expr MINUS term { printf("- subtraction\n"); }
     | term
     ;

term : term MUL factor { printf("* multiplication\n"); }
     | term DIV factor { printf("/ division\n"); }
     | term MOD factor { printf("%% modulo\n"); }
     | factor
     ;

factor : LPAREN expr RPAREN
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
