//Digit Count
#include<stdio.h>
int main()
{
    int n,i=0;
    printf("Haritha R\t126018017\n");
    printf("Enter a number :");
    scanf("%d",&n);
    while (n!=0)
    {
        n/=10;
        i++;
    }
    printf("Number of digits: %d",i);
}
