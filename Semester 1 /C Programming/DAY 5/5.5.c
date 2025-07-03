//Print the array elements in reverse order using recursion.
#include<stdio.h>
int rev(int a[50],int i)
{
    if (i!=0)
    {
        printf("%d\t",a[i]);
        rev(a,i-1);
    }
    else
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int a[50],num,i;
    printf("Haritha\t126018017\n");
    printf("Enter the range : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Reversed string : \n");
    rev(a,num-1);
}