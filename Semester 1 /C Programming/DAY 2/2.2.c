//Largest among four numbers
#include<stdio.h>
int main()
{
    int n,max=0,i;
    printf("Haritha R\t126018017\n");
    printf("Enter four number : ");
    for (i=0;i<=3;i++)
    {
        scanf("%d",&n);
        if (n>max)
        {
            max = n;
        }
    }
    printf("Maximum of 4 numbers : %d",max);
    return 0;
}
