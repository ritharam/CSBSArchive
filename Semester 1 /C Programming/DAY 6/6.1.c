//Store Fibonacci series of a given number in an array.
#include<stdio.h>
void main()
{
    int n,T[20],i;
    T[1]=1;
    T[0]=0;
    printf("Haritha R\t126018017\n");
    printf("Enter the number range : "); 
    scanf("%d", &n);
    printf("Fibonacci Series : \n%d\n%d\n",T[0],T[1]);
    for(i=2;i<=n-1;i++)
    {
        T[i]=T[i-1]+T[i-2];
        printf("%d\n",T[i]);
    }
}