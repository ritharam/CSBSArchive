#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num,i;
    char str[10];
    FILE *fptr;
    fptr = fopen("F2.txt","w");

    if (fptr == NULL)
    {
        printf("Not Accessible");
        exit(1);
    }
    printf("Enter text : ");
    gets(str);
    for(i=0;i!=strlen(str);i++)
    {
        fputc(str[i],fptr);
    }
    //fputs(str,fptr);
    fclose(fptr);
}