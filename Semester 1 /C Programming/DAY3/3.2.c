// Sum of N odd and even natural numbers.
#include<stdio.h>
int main()
{
    int n,i=1,j=0,s1=0,s2=0;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : "); 
    scanf("%d", &n);
    while (i<=n)
    {
            s1+=i;
            i+=2;
    }
    printf("Sum of odd natural numbers : %d\n",s1);
    do {
        if (j%2==0)
        {
            s2+=j;
            j+=2;
        }
    }
    while (j<=n);
    printf("Sum of even natural numbers : %d",s2);
}