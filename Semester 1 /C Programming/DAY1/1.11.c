//Prime number generation.
#include <stdio.h> 
int main() 
{   int n1, n2, i, j, flag; 
    printf("Haritha R\t126018017\n");
    printf("Enter two numbers(intevals): "); 
    scanf("%d %d", &n1, &n2); 
    printf("Prime nos in range %d - %d are: ", n1, n2); 
    for(i=n1+1; i<n2;++i) 
    {
        flag=0; 
        for(j=2;j<=i/2;++j) 
        { 
            if(i%j==0) 
            {
                flag=1; 
                break;
            }
        } 
        if((flag==0)&&(i!=1)) 
            printf("%d\n",i);} }
