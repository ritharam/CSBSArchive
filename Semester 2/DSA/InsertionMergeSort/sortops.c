#include<stdio.h>
#include"sort.h"

void I_sort(int A[],int n){
	int i,j,key=0;
	for(i=1;i<n;i++){
		j = i-1;
		key = A[i];
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j-=1;}
		A[j+1] = key;}
}

void Merge(int A[],int low,int mid,int high){
	int i=low,k =low, j=mid+1 , T[high]; 
	while(i<= mid && j<=high){
		if(A[i] <= A[j]){
			T[k] = A[i];
			i++;}
		else{ 
			T[k] = A[j];
			j++;}
		k++;
		
	}
	while(j<=high){
			
			T[k] = A[j];
			j++;
			k++;}
	while(i <= mid){
			T[k] = A[i];
			i++;
			k++;}
	for (i=low;i<=high;i++) A[i] = T[i];
}
				
void M_sort(int A[], int low, int high){
	if (low < high){ 
		int mid;
		mid = (low+high)/2;
		M_sort(A,low,mid);
		M_sort(A,mid+1,high);
		Merge(A,low,mid,high);
		}
}
