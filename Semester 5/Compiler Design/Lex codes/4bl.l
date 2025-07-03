%{
#include "y.tab.h"
%}

%%

if            { printf("Matched IF\n"); return IF; }
else          { printf("Matched ELSE\n"); return ELSE; }
[a-zA-Z_][a-zA-Z_0-9]*  { printf("Matched ID: %s\n", yytext); return ID; }
0|[1-9][0-9]*	{return NUM;}
\<|\>|\>=|\<=|\==|\!=    { printf("Matched REL: %s\n", yytext); return REL; }
[ \t\r\n]     { /* Ignore whitespace */ }
.             { printf("Matched character: %c\n", yytext[0]); return yytext[0]; }

%%

int yywrap() {
    return 1;
}
