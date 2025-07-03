//Sum of n NATURAL NUMBERS in functions
#include<stdio.h>
int sum(int n)
{
int i,sum=0;
for(i=0;i<=n;i++)
{
sum+=i;
}
printf("Sum : %d",sum);
}

int main()
{
int n;
printf("Haritha\t126018017\n");
printf("Enter a number : ");
scanf("%d",&n);
sum(n);
}
