#include<stdio.h>
#include "Hanoihead.h"

void Hanoi(int n)
{
	FILE *fp = fopen("Output.txt","w");
	createstack(n+3);
	Element x = {n,'A','C','B',13};
step2: 	push(x);
	x = peek();
	if (x.N == 0) goto stepRA;
	Element t1= {x.N-1,x.SN,x.IN,x.DN,7};
	x = t1;
	goto step2;
step7:	x = pop() ;
	x = peek();
	fprintf(fp,"\nMove disc %d from %c to %c",x.N,x.SN,x.DN);
	Element t2= {x.N-1,x.IN,x.DN,x.SN,11};
	x=t2;
	goto step2;
step11: x = pop();
stepRA: x = peek();
	switch(x.RA){
	case 7:
	goto step7;
	case 11:
	goto step11;
	case 13:
	return;}
	fclose(fp);
	
}

int main () 
{
	int n;
	printf("Enter the Number of Discs :");
	scanf("%d",&n);
	Hanoi(n);
	return 0;
} 