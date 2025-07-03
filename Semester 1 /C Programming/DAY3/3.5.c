// Fctorial of a number and Prime numbers
#include<stdio.h>
int main()
{
    int fact=1,n,i,r;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : "); 
    scanf("%d", &n);
    for (i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("Factorial of a number : %d\n",fact);
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
        {
            r++;
        }
    }
    if (r==0 && n!=0)
    {
        printf("%d is a prime number.",n);
    }
    else 
    {
        printf("%d is not a prime number.",n);
    }
}