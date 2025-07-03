//Print all the students name starts with the character ‘S’ or ‘s’ from the class of 60 students.
#include<stdio.h>
#include<string.h>
void main()
{
    char s[60][60];
    int n,i;
    printf("Haritha R\t126018017\n");
    printf("Enter number of students : ");
    scanf("%d",&n);
    printf("Enter the names of the students :");
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    printf("Student name that starts with s or S : \n");
    for (i=0;i<n;i++)
    {
        if (s[i][0]=='s'||s[i][0]=='S')
        {
            printf("%s\n",s);
        }
    }   
}