//decimal to binary, decimal to octal and decimal to hexadecimal by creating individual functions

#include<stdio.h>

int dtb(int n)
{
    int a[100],i,j;
    for (i=0;i<n;i++)
    {
        a[i]=n%2;
        n/=2;
    }
    for (j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
}

int dto(int n)
{
    int a[100],i,j;
    for (i=0;i<n;i++)
    {
        a[i]=n%8;
        n/=8;
    }
    for (j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
}

int dth(int n)
{
    int i = 1, j,T;
    char a[100];
    while (n != 0) {
        T = n % 16;
        if (T < 10)
            T = T + 48;
        else
            T = T + 55;
        a[i++] = T;
        n = n / 16;
    }
    for (j = i - 1; j > 0; j--)
        printf("%c", a[j]);
}

int main()
{
    int n;
    printf("Haritha\t126018017\n");
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("Decimal to Binary : %d\n",dtb(n));
    printf("Decimal to Octal : %d\n",dto(n));
    printf("Decimal to Hexadecimal : %c\n",dth(n));
}
