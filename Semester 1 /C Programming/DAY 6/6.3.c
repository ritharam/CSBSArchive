//Sort the character array from a to z (A to Z) and vice-versa (z to a, Z to a)
#include<stdio.h>
#include<string.h>
int asc(char A[],int n);
int main()
{
    int n,i,j;
    char A[50],T;
    printf("Haritha R\t126018017\n");
    printf("Enter the character array : ");
    scanf("%s",A);
    n=strlen(A); 
    printf("Sorted array in ascending order : ");
    asc(A,n);
    printf("\nSorted array in descending order : ");
    for(i=0;i<n-i;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]<A[j])
            {
                T=A[i];
                A[i]=A[j];
                A[j]=T;
            }
        }
    }
    printf("%s",A);
}

int asc(char A[],int n)
{
    int i,j;
    char T;
        for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                T=A[i];
                A[i]=A[j];
                A[j]=T;
            }    
        }
    }
    printf("%s",A);
}