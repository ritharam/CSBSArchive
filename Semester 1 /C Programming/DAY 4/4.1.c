//Factorial and summation of digits in functions
#include<stdio.h>
int fact(int n)
{
    int i,fact=1;
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("Factorial : %d\n",fact);
    }

int digsum(int n)
{
    int i,sum=0;
    while (n!=0)
    {
        i=n%10;
        sum+=i;
        n/=10;
    }
    printf("Digit summation : %d",sum);
}

int main()
{
    int n;
    printf("Haritha\t126018017\n");
    printf("Enter a number : ");
    scanf("%d",&n);
    fact(n);
    digsum(n);
}