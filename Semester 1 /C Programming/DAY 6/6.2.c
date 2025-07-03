//Sort the given array in ascending order and descending order.
#include<stdio.h>
int main()
{
    int A[100],n,i,j,T;
    printf("Haritha R\t126018017\n");
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements to input : \n");    
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
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
    printf("Elements of array in ascending order :");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }

    for(j=i+1;j<n;j++)
    {
        if(A[i]<A[j])
        {
            T=A[i];
            A[i]=A[j];
            A[j]=T;
        }
    }
    printf("\nElements of array in descending order :");
    for(i=n-1;i>=0;i--)
    {
        printf("%d\t",A[i]);
    }
}
