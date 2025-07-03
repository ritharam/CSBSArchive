//sum of N natural numbers using recursions
#include <stdio.h>
int sum(int n) 
{
    if (n != 0)
        return n + sum(n-1);
    else
        return n;
}
int main() 
{
    int number, result;
    printf("Haritha\t126018017\n");
    printf("Enter an integer : ");
    scanf("%d", &number);
    result = sum(number);
    printf("Sum : %d", result);
    return 0;
}