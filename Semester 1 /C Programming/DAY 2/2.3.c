//Second smallest number among three numbers.
#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Haritha R\t126018017\n");
    printf("Enter three numbers : ");
    scanf("%d %d %d",&a,&b,&c);
    if (a>b && a>c)
        if (b>c)
            printf("Second smallest number : %d",b);
        else
            printf("Second smallest number : %d",c);
    else if (b>c && b>a)
        if (c>a)
            printf("Second smallest number : %d",c);
        else
            printf("Second smallest number : %d",a);
    else
        (a>b)? printf("Second smallest number : %d",a):printf("Second smallest number : %d",b);
}
