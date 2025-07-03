//Fibonacci upto 200 terms.
#include<stdio.h>
int main()
{
    int sum = 0, n=200;
    int a = 0;
    int b = 1;
    printf("Haritha R\t126018017\n");
    printf("Fibonacci series:\n ");
    while(sum <= n)
    {
        printf("%d ", sum);
        a = b; 
        b = sum;
        sum = a + b; 
    }
    return 0;
}