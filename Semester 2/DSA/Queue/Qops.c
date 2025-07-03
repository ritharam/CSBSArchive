#include<stdlib.h>
#include<stdio.h>
#include "QHead.h"
static Queue qu;

void createqueue(int n){
	qu.S = (Element*)calloc(sizeof(Element),n+1);
	qu.MAX_SIZE = n;
	qu.front = 0;
	qu.rear = 0;
}

int ISFULL() {
	if (qu.rear >= qu.MAX_SIZE)
		return 1;
	else 
		return 0;
}

int ISEMPTY() {
	if (qu.rear == -1)
		return 1;
	else 
		return 0;
}

void ENQ(Element x){
	if(ISFULL()){
		printf("\nQueue is FULL, Cannot Insert");}
	else{
		qu.rear+=1;
		qu.S[qu.rear] = x;
		if (qu.front==-1) 
			qu.front =0; }
}	

Element DEQ () {
	if (ISEMPTY()){
		printf("Queue is empty...");
		return -1;}
	else{
		Element x = qu.S[qu.front];
        if (qu.front == qu.rear)
        qu.front = qu.rear =0;
        else 
        qu.front +=1;
		return x; }
}

void multiENQ(char fname[]){
	Element x;
	FILE *fp = fopen(fname,"r");
	while(!feof(fp)){
		fscanf(fp, "%d", &x);
		if(!feof(fp))
			ENQ(x);}
	fclose(fp);
}

void multiDEQ(char fname[], int m){
	Element x;
	FILE *fp = fopen(fname,"w");
	int count=0;
	if (ISEMPTY()) 
		printf("Queue is Empty");
	while (!ISEMPTY() && count < m) {
		x = DEQ();
		fprintf(fp, "%d", x);
		count++; } 
	fclose(fp);
}

