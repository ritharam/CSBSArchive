//the LCM and GCD using functions
#include <stdio.h>

int gcd(int n1,int n2)
{
    int gcd,i ; 
    for(i=1;i<=n1 && i <= n2;++i)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd = i; 
        } 
    }
    printf("\nThe GCD is : %d", gcd) ; 
}

int lcm(int n1,int n2)
{
    int max;
    max = (n1 > n2) ? n1 : n2;
    while (1) 
    {
        if ((max % n1 == 0) && (max % n2 == 0)) {
            printf("The LCM of %d and %d is %d.", n1, n2, max);
            break;
        }
    ++max;
    }
}

int main()
{
    int n1,n2;
    printf("Haritha\t126018017\n");
    printf("Enter two numbers : ");
    scanf("%d %d",&n1,&n2);
    gcd(n1,n2);
    lcm(n1,n2);
    return 0;
}
