//To check whether a number is prime using function pointers 
#include<stdio.h> 
void isprime(int); 
void (*fprime)(int); 
void main() 
{
    int n,i,j; 
    fprime=isprime; 
    printf("Haritha\t126018017\n");
    printf("Enter the number "); 
    scanf("%d",&n); 
    (*fprime)(n); 
    getchar(); 
} 
void isprime(int a) 
{
    int i,fg=0; 
    for(i=2;i<a;i++) 
    {
        if(a%i==0) 
        fg=1;
    } 
    if (fg==0) 
    printf("Prime"); 
    else 
    printf("Not prime"); 
}