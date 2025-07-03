//Print the string in reverse order using recursion.
#include<stdio.h>
#include <string.h>
int rev(char a[50],int i)
{
    if (i!=0)
    {
        printf("%c",a[i]);
        rev(a,i-1);
    }
    else
    {
        printf("%c",a[i]);
    }
}
int main()
{
    int num,i;
    char a[50];
    printf("Haritha\t126018017\n");
    printf("Enter String : ");
    scanf("%s",a);
    num=strlen(a);
    printf("\nReversed string :");
    rev(a,num-1);
}