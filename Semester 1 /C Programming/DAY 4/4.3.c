//Factorial and fibonacci numbers in functions
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

int fibo(int n)
{
int t1=0,t2=1,T,i;
printf("Fibonacci series : %d\n%d\n",t1,t2);
for (i=3;i<=n;i++)
{
T=t1+t2;
t1=t2;
t2=T;
printf("%d\n",T);
}
}

int main()
{
int n;
printf("Haritha\t126018017\n");
printf("Enter a number : ");
scanf("%d",&n);
fact(n);
fibo(n);
}