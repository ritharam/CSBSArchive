//Factorial and Fibonacci series using recursions.
#include <stdio.h>
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
int fibo(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
    return 1;
    }
    else
    {
    return(fibo(num - 1) + fibo(num - 2));
    }
}
int main()
{
    int num,res,n,i;
    printf("Haritha\t126018017\n");
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Fibonacci series : \n");
    for (i=0;i<=num-1;i++)
    {
        printf("%d\t",fibo(i));
    }
    printf("\nFactorial : %d",fact(num));
    return 0;
}


