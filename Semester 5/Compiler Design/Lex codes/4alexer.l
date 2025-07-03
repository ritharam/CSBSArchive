/*%{
#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z_0-9]*   return VAR;
[0-9]+                   return NUMBER;
.                        return yytext[0];
%%

int yywrap() {
    return 1;
}
*/

%{
#include "y.tab.h"
%}
%%
[0-9]+ { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z]+   { yylval.id = strdup(yytext); return ID; }
. { }
%%
int yywrap() {
return 1;
}
