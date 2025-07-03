// Odd or Even, Positive or Negative and Zero
#include<stdio.h>
int main()
{
    int n,a;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : ");
    scanf("%d",&n);
    if (n>0)
        printf("Positive\n");
    else if (n<0)
        printf("Negative\n");
    else
        printf("Zero\n");
    (n%2==0)?printf("Even"):printf("Odd");
}
