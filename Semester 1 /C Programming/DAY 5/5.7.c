//Arithmetic calculator using recursion.
#include<stdio.h>
int add(int n,int m)
{
    if (m!=0)
    {
        return(1+add(n,m-1));
    }
    else
    {
        return (n);
    }
}
int sub(int n,int m)
{
    if (m!=0)

    {
        return(sub(n,m-1)-1);
    }
    else
    {
        return (n);
    }
}
int mul(int n,int m)
{
    if (m!=1)

    {
        return(n+mul(n,m-1));
    }
    else
    {
        return (n);
    }
}
int div(int n,int m)
{
    if (m!=1)

    {
        return(div(n,m-1)-n);
    }
    else
    {
        return (n);
    }
}

int main()
{
    int n,m,sum,pro,dif,qou;
    printf("Haritha\t126018017\n");
    printf("Enter two numbers : ");
    scanf(" %d %d",&n,&m);
    sum=add(n,m);
    pro=mul(n,m);
    dif=sub(n,m);
    qou=div(n,m);
    printf("Multiplication : %d",pro);
    printf("\n");
    printf("Addition : %d",sum);
    printf("\n");
    printf("Subraction : %d",dif);
    printf("\n");
    printf("Division : %d",qou);

}