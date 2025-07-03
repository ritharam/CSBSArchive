#include<stdio.h>
#include"sort.h"
int main (){
	int n,i,op;
	printf("Enter the size of the Array :");
	scanf("%d",&n);
	int A[n],B[n];
	for(i=0;i<n;i++){
		printf("Enter Element %d :",i+1);
		scanf("%d",&A[i]);}
	printf("Before sorting :");
	for(i=0;i<n;i++){
		printf("\t%d",A[i]);}	
	printf("Sort Using\n1.Insertion Sort\n2.Merge Sort");
	scanf("%d",&op);
	switch(op){
		case 1:I_sort(A,n); break;
		case 2:M_sort(A,0,n-1); break;}
		printf("\nAfter sorting :");
	for(i=0;i<n;i++){
		printf("\t%d",A[i]);}
}
	
