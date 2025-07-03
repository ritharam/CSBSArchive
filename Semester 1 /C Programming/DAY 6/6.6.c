//Store the names 60 students and separate the names with odd length and even length.
#include<stdio.h>
#include<string.h>
int main()
{
    char name[60][60],array1[60][60],array2[60][60];
    int o=0,e=0;
    int i,n;
    printf("Haritha R\t126018017\n");
    printf("Enter the number of names : ");
    scanf("%d",&n);
    printf("Enter the names : ");
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
    }
    for(i=0;i<5;i++)
    {
        if(strlen(name[i])%2!=0)
        {
            strcpy(array1[o],name[i]);
            o++;
        }
        else if (strlen(name[i])%2==0)
        {
            
            strcpy(array2[e],name[i]);
            e++;
        }
        else
        {
            //
        }
    }
    printf("Names with Even Number of Charescters:\n");
    for(i=0;i<=e;i++)
    {
        printf("%s\n",array2[i]);
    }
    printf("Names with odd Number of Charescters:\n");
    for(i=0;i<=o;i++)
    {
        printf("%s\n",array1[i]);
    }
}