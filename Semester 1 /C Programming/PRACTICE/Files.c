#include<stdio.h>
#include<stdlib.h>

int main()
{
    char num;
    char str[10];
    FILE *fptr;
    fptr = fopen("F1.txt","r");
    // printf("Enter text : ");
    // scanf("%s",str);
    //fprintf(fptr,"%s",&str);
    fscanf(fptr,"%s",num);
    printf("%s",num);
    fclose(fptr);
}