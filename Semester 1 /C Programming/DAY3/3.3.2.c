// Sequence 2
#include <stdio.h>
int main()
{
    int i,j,k;
    printf("Haritha R\t126018017\n");
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=4-i;j++)
        {
            printf(" ");
        }
        for (k=0;k<=i;k++)
        {
            printf("*");
        }
    printf("\n");
    }
}
