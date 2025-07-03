//5 subject marks  and average.
#include<stdio.h>
int main()
{   int a,b,c,d,e,sum,rn,avg;
    char name[10];
    printf("Haritha R\t126018017\n");
    printf("Enter marks of five subjects : ");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    printf("Enter name :\n ");
    scanf("%s",&name);
    printf("Enter register number : ");
    scanf("%d",&rn);
    sum=a+b+c+d+e;
    avg=sum/5;
    printf("Name : %s\nRegister Number : %d\nMark1 : %d\nMark2 : %d\nMark3 : %d\nMark4 : %d\nMark5 : %d\nSum : %d\nAverage : %d",name,rn,a,b,c,d,e,sum,avg);
    return 0;
}
