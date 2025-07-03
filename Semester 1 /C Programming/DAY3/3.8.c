//Palindrome or not.
#include<stdio.h>
int main()
{
int n,sum=0,digit,a;
printf("Haritha\t126018017\n");
printf("Enter a number : ");
scanf("%d",&n);
a=n;
for (;n>0;n/=10)
{
digit=n%10;
sum=sum*10+digit;
}
if (sum==a)
printf("The number is a palindrome.");
else
printf("The number is not a palindrome.");
}