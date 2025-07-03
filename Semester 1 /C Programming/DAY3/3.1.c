// Sum of N natural numbers.
#include<stdio.h>
int main()
{
    int sum=0,n,i;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : "); 
    scanf("%d", &n);
    for (i=0;i<=n;i++)
    {
        sum+=i;
    }
    printf("Sum of %d natural number : %d",n,sum);
}