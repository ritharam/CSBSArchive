%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 0; /* For generating temporary variables */
int symbolTable[26]; /* Symbol table for variables a-z */

/* Helper function to generate a temporary variable */
void generateTempVar(char* result) {
    sprintf(result, "t%d", ++tempCount);
}

%}

/* Declare YYSTYPE as a union to hold different types */
%union {
    int num;       /* For holding numeric values */
    char* id;      /* For holding variable names and temporary variables */
}

/* Token declarations with types */
%token <id> IDENTIFIER
%token <num> NUMBER
%token ASSIGN PLUS MULTIPLY SEMICOLON
%type <id> expression term factor

%left PLUS
%left MULTIPLY

%%

statement:
    IDENTIFIER ASSIGN expression SEMICOLON {
        symbolTable[$1[0] - 'a'] = atoi($3);  /* Store the result in the symbol table */
        printf("%c = %s\n", $1[0], $3);
    }
;

expression:
    expression PLUS term {
        char temp[10];
        generateTempVar(temp);
        printf("%s = %s + %s\n", temp, $1, $3);
        $$ = strdup(temp);  /* Store the result in a temporary variable */
    }
    | term { $$ = $1; }
;

term:
    term MULTIPLY factor {
        char temp[10];
        generateTempVar(temp);
        printf("%s = %s * %s\n", temp, $1, $3);
        $$ = strdup(temp);  /* Store the result in a temporary variable */
    }
    | factor { $$ = $1; }
;

factor:
    IDENTIFIER {
        char temp[10];
        sprintf(temp, "%d", symbolTable[$1[0] - 'a']);  /* Fetch the variable value from the symbol table */
        $$ = strdup(temp);  /* Store the value as a string */
    }
    | NUMBER {
        char temp[10];
        sprintf(temp, "%d", $1);  /* Convert the number to a string */
        $$ = strdup(temp);  /* Store the value as a string */
    }
;

%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

int yyerror(char* s) {
    printf("Error: %s\n", s);
    return 0;
}
