//Split the array into two separate arrays with integer values and combine two integer arrays into a single array.
#include <stdio.h>
int main()
{
    int p=0,n=0,i,num,a[50],pos[50],neg[50],join[50];
    printf("Haritha R\t126018017\n");
    printf("Enter the limit:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<num;i++)
    {
        if(a[i]>=0)
        {
            pos[p]=a[i];
            p++;
        }
        else
        {
            neg[n]=a[i];
            n++;
        }
    }
    printf("Positive Integers:");
    for(i=0;i<p;i++)
    {
        join[i]=pos[i];
        printf("%d ",pos[i]);
    }
    printf("\nNegative Integers:");
    for(i=0;i<n;i++)
    {
        join[p+i]=neg[i];
        printf("%d ",neg[i]);
    }
    printf("\nJoined Array:");
    for(i=0;i<n+p;i++)
    {
        printf("%d ",join[i]);
    }

}