#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n,count=0;
    char str[50];
    printf("Enter a string : ");
    scanf("%s",str);
    n=strlen(str);
    for (i=0;i<n;i++)
    {
        count =1;
        if (str[i])
        {
        for (j=i+1;j<n;j++)
        {
            if (str[i]==str[j])
            {
                count++;
                str[j]='\0';
            }
        }
        printf("Character %c in frequency %d.\n ",str[i],count);
        }
    }
    return 0;
}