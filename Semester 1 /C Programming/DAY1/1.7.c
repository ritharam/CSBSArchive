//5 subject marks and average.
#include <stdio.h>
int main()
{
    int a,b,c,d,e,sum,avg;
    printf("Haritha R\t126018017\n");
    printf("Input marks in five subjects : ");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    sum=a+b+c+d+e;
    avg=sum/5;
    printf("Sum : %d\nAverage : %d",sum,avg);
}
