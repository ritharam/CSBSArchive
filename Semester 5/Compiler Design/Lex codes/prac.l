%{
#include<stdio.h>
FILE *ipf, *c, *p;
%}
%%
class|public|namespace {fprintf(c,"%s ",yytext);}
def|for|import {fprintf(p,"%s ",yytext);}
. {}
%%
int main(){
    ipf = fopen("inp.txt","r");
    c = fopen("c++.txt","a");
    p = fopen("python.txt","a");
    yyin = ipf;
    yylex();
    fclose(ipf);
    fclose(c);
    fclose(p);
    return 0;
}
int yywrap(){return 1;}
