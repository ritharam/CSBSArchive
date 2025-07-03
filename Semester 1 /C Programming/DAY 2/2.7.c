// Week day switch case
#include<stdio.h>
void main()
{
int week;
printf("Haritha R\t126018017\n");
printf("Enter any Week number : ");
scanf("%d",&week);
switch(week)
{   case 1: printf("Sunday");break;
    case 2: printf("Monday");break;
    case 3: printf("Tuesday");break;
    case 4: printf("Hednesday");break;
    case 5: printf("Thursday");break;
    case 6: printf("Friday");break;
    case 7: printf("Saturday");break;
    default : printf("Enter a week number between 1 to 7.");
    break;
}
}
