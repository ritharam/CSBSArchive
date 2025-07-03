#include<stdlib.h>
#include<stdio.h>
#include "Hanoihead.h"
static Stack sta;

void createstack(int n){
	sta.S = (Element*)calloc(sizeof(Element),n);
	sta.MAX_SIZE = n;
	sta.top = -1;
}

int ISFULL() {
	if (sta.top >= sta.MAX_SIZE)
		return 1;
	else 
		return 0;
}

int ISEMPTY() {
	if (sta.top == -1)
		return 1;
	else 
		return 0;
}

void push(Element x){	
	if(ISFULL()){
		printf("\nStack is FULL, Cannot Insert");}
	else{
		sta.top+=1;
		sta.S[sta.top] = x; }
}
Element pop () {
	Element x = {-1,' ',' ',' ',0};
	if (ISEMPTY()){
		return x;}
	else{
		x = sta.S[sta.top];
		sta.top--;
		return x; }
}
Element peek(){
	Element x = {-1,' ',' ',' ',0};
	if (ISEMPTY()){
		return x;}
	else{
		return sta.S[sta.top];
		}
}
