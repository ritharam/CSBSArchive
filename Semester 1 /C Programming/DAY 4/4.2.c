//Largest number and smallest number by creating two different functions.
#include <stdio.h>
int small(int a[],int num)
{
    int i;
    int s=a[0];
    
    for(i=1;i<num;i++)
    {
        if (s>a[i])
        {
            s=a[i];
        }
    }
    printf("%d\n",s);
    
}
int large(int a[],int num)
{
    int i;
    int l=a[0];
    
    for(i=1;i<num;i++)
    {
        if (l<a[i])
        {
            l=a[i];
        }
    }
    printf("%d\n",l);
    
}
int main() 
{   int a[50],i,num;
    printf("Haritha\t126018017\n");
    printf("Enter the number of elements :");
    scanf("%d",&num);
    printf("Input the array elements : ");
    for(i=0;i<num;++i)
        scanf("%d",&a[i]);
    printf("\n");
    printf("Largest Number : ",large(a,num));
    printf("Smallest Number : ",small(a,num));
}

