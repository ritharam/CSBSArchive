//Add two complex numbers 
#include<stdio.h> 
typedef struct complex 
{ 
    float real; 
    float imag; 
}complex; 
complex add(complex n1,complex n2); 
void main() 
{ 
    complex n1,n2,temp;
    printf("Haritha\t126018017\n"); 
    printf("For 1st complex number \n"); 
    printf("Enter real and imaginary respectively:\n"); 
    scanf("%f%f",&n1.real,&n1.imag); 
    printf("\nFor 2nd complex number \n"); 
    printf("Enter real and imaginary respectively:\n"); 
    scanf("%f%f",&n2.real,&n2.imag); 
    temp=add(n1,n2); 
    printf("Sum=%.1f+%.1fi",temp.real,temp.imag); 
} 
complex add(complex n1,complex n2) 
{ 
    complex temp; 
    temp.real=n1.real+n2.real; 
    temp.imag=n1.imag+n2.imag; 
    return(temp); 
}