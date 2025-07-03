#include "SearchType.h"
#include<stdio.h>
#define MAXSIZE 10

int main() {
	char ch,g;	
	Element A[MAXSIZE],x;
	int n, i, pos;
	printf("\nEnter Number of elements in the array :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Element %d :",i+1);
		scanf("%d",&A[i]);}
	printf("\nEnter the element to search :");
	scanf("%d",&x);
	printf("\nType B to use Binary Search OR Type R to use Recursive Binary Search :");
	scanf("%c",&g);
	scanf("%c",&ch);
	switch(ch){
		case 'B':
		pos = BinarySearch(A,n,x);
		break;
		case 'R':
		pos = RBinarySearch(A,0,n-1,x);

	}
	if (pos !=-1)
		printf("\nElement %d is present in location %d",x,pos);
	else 
		printf("\nElement Not Found!!!!");
	return 0;
}


