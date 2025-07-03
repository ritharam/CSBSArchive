// Mark Pass or Fail.
#include<stdio.h>
void main()
{   int m1,m2,m3,m4,m5,sum,avg,rn;
    char name[10] ; 
    printf("Haritha R\t126018017\n");
    printf ("Enter name and Register number: ");
    scanf("%s %d",&name,&rn);
    printf ("Enter marks in 5 subjects:");
    scanf ("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);
    sum = m1+m2+m3+m4+m5;
    avg=sum/5;
    if (m1>50 && m2>50 && m3>50 && m4>50 && m5>50)
    {   printf("PASS\n");
        printf ("Name:%s\nRegister Number : %d\nAverage : %d\n", name,rn,avg);
        if(avg>=75)
        {printf("First class with distinction.");}
        else if(avg>=60 && avg<75)
        {printf ("First class");}
        else
        {printf("Second class");}}
    else
    {printf ("FAIL");
    printf ("Name : %s\n Register Number:%d\n Average : %d",name,rn, avg);}}

