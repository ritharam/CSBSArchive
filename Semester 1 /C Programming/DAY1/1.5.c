//Simple Interest and Compound Interest.
#include <stdio.h>
#include <math.h>
int main()
{
int p,n,r,CI;
printf("Haritha R\t126018017\n");
printf("Enter the Principal Amount :");
scanf("%d",&p);
printf("Enter number of years :");
scanf("%d",&n);
printf("Enter the rate :");
scanf("%d",&r);
printf("Simple Interest : %d\n",(p*n*r)/100);
CI =p*pow((1+r/100),n)-p;
printf("Compound Interest : %d",CI);
return 0;
}
