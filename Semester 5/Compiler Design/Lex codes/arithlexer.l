%{
#include "y.tab.h"  
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
%}

%%
[0-9]+      { yylval.num = atoi(yytext); return NUM; }
[a-zA-Z]+   { yylval.id = strdup(yytext); return ID; }
.           { return yytext[0]; } 
\n          {return 0;}
%%
