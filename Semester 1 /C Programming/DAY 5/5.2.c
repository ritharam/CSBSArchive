//Largest number and smallest number by creating two different recursions.
#include <stdio.h>
int small(int a[],int i,int min)
{
    if (i>0)
    {
        if (min>a[i])
        {
            small(a,i-1,a[i]);
        }
        else
        {
            small(a,i-1,min);
        }

    }
    if (i==0)
    {
        if (min>a[i])
        {
            printf("Smallest Number : %d",a[i]);
        }
        else
        {
            printf("Smallest Number : %d",min);
        }

    }
    
}

int large(int a[],int i,int max)
{
    if (i>0)
    {
        if (max<a[i])
        {
            large(a,i-1,a[i]);
        }
        else
        {
            large(a,i-1,max);
        }

    }
    if (i==0)
    {
        if (max<a[i])
        {
            printf("Largest Number : %d",a[i]);
        }
        else
        {
            printf("Largest Number : %d",max);
        }

    }
    
}

int main() 
{   int a[50],i,num;
    printf("Haritha\t126018017\n");
    printf("Enter the number of elements :");
    scanf("%d",&num);
    printf("Input the array elements : ");
    for(i=0;i<num;++i)
    {
        scanf("%d",&a[i]);
    }
    large(a,num-1,a[num-1]);
    printf("\n");
    small(a,num-1,a[num-1]);
}