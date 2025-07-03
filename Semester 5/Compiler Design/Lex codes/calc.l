%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+ { yylval.num1 = atoi(yytext); return INT; }
[0-9]\.[0-9]+ { yylval.num = atof(yytext); return FLOAT; }
[ \t\r\n] {}
. return yytext[0];
%%

int yywrap() { return 1; } 
