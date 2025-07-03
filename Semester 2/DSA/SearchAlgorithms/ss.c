#include<stdio.h>

void swap(int *x,int *y);
int *Selection(int A[], int n);

void main(){
    int i;
    int A[] ={1,5,2,4,3};
    for(i=0;i<5;i++) printf("%d",A[i]);
    printf("\n");
    Selection(A,5);
    for(i=0;i<5;i++) printf("%d",A[i]);
    
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int *Selection(int A[],int n){
    int i,j,min;
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[min]) min = j;
        }
        if(min != i) swap(&A[min],&A[i]);
    }
}
