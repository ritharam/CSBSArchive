//Search the number and character from array.
#include<stdio.h>
int is(int a[50],int x)
{
    int i,flag=0,s;
    printf("Enter the digit to search:");
    scanf("%d",&s);
    for(i=0;i<x;i++)
    {
        if(s==a[i])
        {
            flag=1;            
        }
    }
    if(flag==0)
    {
        printf("Search Element not found");
    }
    else if (flag==1)
    {
        printf("Search Element found");
    }
}
int cs(char a[50],int x)
{
    int i,flag=0,s;
    printf("Enter the charecter to search:");
    scanf("%c",&s);
    for(i=0;i<x;i++)
    {
        if(s==a[i])
        {
            flag=1;            
        }
    }
    if(flag==0)
    {
        printf("Search Element not found");
    }
    else if (flag==1)
    {
        printf("Search Element found");
    }
}
int main()
{
    int j,i,a[50],num,ch;
    char b[50];
    printf("Haritha R\t126018017\n");
    printf("Choose : \n1.Charecter\n2.Digit\n");
    scanf("%d",&ch);
    printf("Enter Limit:");
    scanf("%d",&num);
    if(ch==2)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
        }
    is(a,num);
    }
    else if(ch==1)
    {
        printf("x");
        for(j=0;j<num;j++)
        {
            scanf("%s",b[i]);
        }
    cs(b,num);
    }
}