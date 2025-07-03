// Factorial of a number
#include<stdio.h>
int main()
{
    int fact=1,n,i;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : "); 
    scanf("%d", &n);
    for (i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("Factorial of a number : %d",fact);
}