#include<stdio.h>
#include<string.h>
int main()
{
    char str[50],str1[50],r[50],r1[50],copy[50];  
    FILE *fptr,*ptr;
    fptr = fopen("Cars.txt","r");
    ptr = fopen("Bikes.txt","r");
    printf("Enter 10 bike names : ");
    scanf("%s",str);
    printf("Enter 10 car names : ");
    scanf("%s",str1);
    //fprintf(fptr,"%s",&str);
    //fprintf(ptr,"%s",&str1);
    fscanf(fptr,"%s",&r1);
    fscanf(ptr,"%s",&r);
    strcpy(copy,r1);
    strcpy(copy,r);
    printf("Text : %s",copy);
}