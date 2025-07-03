// Parser for Arithmetic Expression 

%{
#include "y.tab.h"
%}

%%

[0-9]+    { yylval = atoi(yytext); return NUMBER; }
"+"       { return '+'; }
[ 	]     { /* Ignore whitespace */ }

        { return '\n'; }
.         { /* Ignore any other characters */ }

%%

int yywrap() {
    return 1;
}
