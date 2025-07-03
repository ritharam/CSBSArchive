%{
#include"y.tab.h"
%}

%%

for            { printf("Matched FOR\n"); return FOR; }
while          { printf("Matched WHILE\n"); return WHILE; }
do	       { printf("Matched DO\n"); return DO; }
[a-zA-Z_][a-zA-Z_0-9]*  { printf("Matched ID: %s\n", yytext); return ID; }
\<|\>|\>=|\<=|\==|\!=    { printf("Matched REL: %s\n", yytext); return REL; }
0|[1-9][0-9]* {return NUM;}
"++"		{return INC;}
[ \t\r\n]     { /* Ignore whitespace */ }
.             { printf("Matched character: %c\n", yytext[0]); return yytext[0]; }

%%

int yywrap() {
	return 1;
}
