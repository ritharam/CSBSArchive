//Categorize uppercase array, lowercase array, numbers (0 to 9) array.
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char str[100],U[10],L[10],N[10];
    int u=0,l=0,n=0;
    printf("Haritha R\t126018017\n");
    printf("Enter a string : ");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        if (isupper(str[i]))
        {
            U[u++]=str[i];
        }
        else if (islower(str[i]))
        {
            L[l++]=str[i];
        }
        else if (isdigit(str[i]))
        {
            N[n++]=str[i];
        }
    }
    printf("Number of uppercase : %d\n",u);
    printf("Number of lowercase : %d\n",l);
    printf("Number of digits : %d\n",n);
    printf("Elemants in Uppercase array : \n");
    for(int i=0;i<u;i++)
    {
        printf("%c ",U[i]);
    }
    printf("\nElemants in Lowercase array : \n");
    for(int i=0;i<l;i++)
    {
        printf("%c ",L[i]);
    }
    printf("\nElemants in Digits array : \n");
    for(int i=0;i<n;i++)
    {
        printf("%c ",N[i]);
    }
}