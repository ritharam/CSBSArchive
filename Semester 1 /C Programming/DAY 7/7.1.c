//Area and perimeter of circle using pointers
#include<stdio.h>
#define PI 3.14
 int main()
{
  float r, Area,Per;
  float *R, *A,*P;
  R= &r;
  A=&Area;
  P=&Per;
  printf("Haritha\t126018017\n");
  printf("Enter the radius of Circle: ");
  scanf("%f",R);
  *A = PI*(*R)*(*R);
  *P = 2*PI*(*R);
  printf("The Area of Cicle with radius %.3f = %.3f\n", *R, *A);
  printf("The Perimeter of Cicle with radius %.3f = %.3f\n", *R, *P);
  return 0;
}