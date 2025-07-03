%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%token FOR WHILE DO
%token ID NUM REL

%%
S : FOR '(' assign ';' C ';' assign ')' '{' S '}'	{printf("For");}
  | WHILE '(' C ')' '{' S '}'			{printf("While");}	
  | DO '{' S '}' WHILE '(' C ')' ';'		{printf("Do-While");}
  | assign ';'
  ;
  
  
C : id REL id
  ;
  
assign : id '=' e {printf("Assignment");}
       | id '+=' e
       | id '++'
       ;
      
e : e '+' t {printf("Add");}
  | t
  ;
  
t : t '*' f {printf("Mul");}
  | f
  ;
  
f : '(' e ')'
  | val
  ;
  
id : ID
   ;
 
val: id
   | NUM
   ;

%%

int main(){
	if (yyparse()){
	printf("Invalid");}
	else {printf("Valid");}
}

void yyerror(const char *s){
fprintf(stderr,"Error: %s\n",s);}
