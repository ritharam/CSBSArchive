%{
#include "y.tab.h"
%}

%%

if              { return IF; }
else            { return ELSE; }

for             { return FOR; }
while           { return WHILE; }
do              { return DO; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return EQ; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }  /* Added '{' for function body */
"}"             { return RBRACE; }  /* Added '}' for function body */
","             { return COMMA; }
";"             { return SEMICOL; }

"int"           { return INT; }      /* Added support for 'int' type */
\".*\"          { return STR; }
0|[1-9][0-9]*   { return NUM; }
[a-zA-Z_][a-zA-Z_0-9]*  { return ID; }

\<|\>|\>\=|\<\=|\=\=|\!\= { return REL; }

[ \t\r\n]       { /* Ignore whitespace */ }
.               { return yytext[0]; }

%%

int yywrap() { return 1; }
