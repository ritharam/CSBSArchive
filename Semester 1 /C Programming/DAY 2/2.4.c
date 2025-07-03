//Largest number among three using ternary operator
#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Haritha R\t126018017\n");
    printf("Enter three numbers : ");
    scanf("%d %d %d",&a,&b,&c);
    (a>b && a>c)? printf("Largest number : %d",a):(b>c)? printf("Largest number : %d",b):printf("Largest number : %d",c);
}
