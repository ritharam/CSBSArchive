// Quadrants
#include<stdio.h>
int main()
{
int x,y;
printf("Haritha R\t126018017\n");
printf("Enter the two coordinates:");
scanf("%d %d",&x,&y);
if(x>0 && y>0)
printf ("First Quadrant");
else if(x<0 && y>0)
printf ("Second Quadrant");
else if (x<0 && y<0)
printf("Third Quadrant");
else
printf("Fourth Quadrant");
}
