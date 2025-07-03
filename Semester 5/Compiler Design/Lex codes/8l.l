%{
#include"y.tab.h"
%}
%%
[0-9]+ {yylval.num = atoi(yytext); return NUM;}
[a-zA-Z_][a-zA-Z_0-9]* {yylval.id = yytext; return ID;}
[\t\n\r ] {}
. return yytext[0];
%%
int yywrap(){return 1;}
