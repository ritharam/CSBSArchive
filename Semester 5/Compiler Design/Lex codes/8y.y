%{
#include<stdio.h>
extern int yylex();
void yyerror(const char* s);
int temp = 0;
%}
%union{
    int num ;
    char *id;
}
%token <num> NUM
%token <id> ID  
%type <num> E T F

%%
S : E '=' E {printf("t%d = t%d\n",$1,$3);} | E ;

E : E '+' T {printf("t%d = t%d + t%d\n",temp,$1,$3); $$ = temp++;} |
    E '-' T {printf("t%d = t%d - t%d\n",temp,$1,$3); $$ = temp++;} |
    T ;

T : T '*' F {printf("t%d = t%d * t%d\n",temp,$1,$3); $$ = temp++;} |
    T '/' F {printf("t%d = t%d / t%d\n",temp,$1,$3); $$ = temp++;} |
    F ;

F : '(' E ')' {$$ = $2;} |
    NUM {printf("t%d = %d\n",temp,$1); $$=temp++;} |
    ID {printf("t%d = %s\n",temp,$1); $$=temp++;} ;
%%
int main(){
    if(yyparse()==0){printf("Parsing Successfull");}
    else{printf("Parsing Failed");}
}
void yyerror(const char* s){
    fprintf(stderr,"Compile Error : %s",s);
}
