//Factorial and summation of digits in recursions
#include<stdio.h>
int fact(int num)
{
    if (num!=1)
    {
        return(num*fact(num-1));
    }
    else
    {
        return(1);
    }
}
int dig(int num)
{
    if(num!=0)
    {
        return (num%10+dig(num/10));
    }
    else
    {
        return(0);
    }
}
int main()
{
    int num,digi;
    long long int pro;
    printf("Haritha\t126018017\n");
    printf("Enter a number : ");
    scanf("%d",&num);
    pro=fact(num);
    digi=dig(num);
    printf("%lld\n",pro);
    printf("%d",digi);
}