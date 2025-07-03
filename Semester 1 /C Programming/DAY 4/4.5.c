//Array elements in reverse order using function
#include<stdio.h>
int rev(int a[],int num)
{
    int i;
    for(i=num-1;i>=0;--i)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
int main() 
{   int a[50],i,num;
    printf("Haritha\t126018017\n");
    printf("Enter the number of elements :");
    scanf("%d",&num);
    printf("Input the array elements : ");
    for(i=0;i<num;++i)
        scanf("%d",&a[i]);
    printf("After reversal : ",rev(a,num));
}
