%{
#include "y.tab.h"  /* Include YACC-generated header */
%}

%%

[a-zA-Z][a-zA-Z0-9]*      { yylval.id = strdup(yytext); return IDENTIFIER; }  /* Variables */
[0-9]+                    { yylval.num = atoi(yytext); return NUMBER; }       /* Numbers */
"="                       { return ASSIGN; }      /* Assignment */
"+"                       { return PLUS; }        /* Addition */
"*"                       { return MULTIPLY; }    /* Multiplication */
";"                       { return SEMICOLON; }   /* Statement terminator */
[ \t\n]+                  { /* Ignore whitespaces */ }
.                         { /* Catch-all for other characters */ }

%%

int yywrap() {
    return 1;
}
