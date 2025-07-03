// Switch case program
#include<stdio.h>
int main()
{   int n,r;
    printf("Haritha R\t126018017\n");
    printf("Enter a number : ");
    scanf("%d",&n);
    if (n<=0)
        r=0;
    else if (n%2==0)
        r=1;
    else if (n%3==0)
        r=2;
    else if (n%2==1)
        r=3;
    switch(r)
    {
        case 0: printf("You have given improper input for this program."); break;
        case 1: printf("Square : %d",n*n); break;
        case 2: printf("Cube : %d",n*n*n); break;
        case 3: printf("Odd number : %d",n*100); break;
    }
    return 0;
}
