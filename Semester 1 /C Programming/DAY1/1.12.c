// Fibonacci Series
#include<stdio.h>
void main()
{
    int t1=0,t2=1,n,T,i;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : "); 
    scanf("%d", &n);
    printf("Fibonacci Series : \n%d\n%d\n",t1,t2);
    for(i=3;i<=n;i++)
    {
        T=t1+t2;
        t1=t2;
        t2=T;
        printf("%d\n",T);
    }
}