//LCM and GCD using recursion
#include <stdio.h>
int gcd(int m,int n)
{
    int x;
    if(m<n)
    {
        gcd(n,m);
    }
    else
    {
        x=m%n;
        if(x!=0)
        {
           gcd(n,x); 
        }
        else
        {
            return(n);
        }
    }
}

int lcm(int m,int n,int x)
{
    if (n>m)
    {
        lcm(n,m,n);
    }
    else
    {
        if(x<=m*n)
        {
            if ((x%m==0)&&(x%n==0))
            {
                return (x);
            }
            else
            {
                lcm(m,n,x+1);
            }
        }
       
    }
}
int main()
{
    int m,n,g,l;
    printf("Haritha\t126018017\n");
    printf("Enter two numbers : ");
    scanf("%d %d",&m,&n);
    g=gcd(m,n);
    printf("GCD: %d",g);
    printf("\n");
    l=lcm(m,n,1);
    printf("LCM: %d",l);
}