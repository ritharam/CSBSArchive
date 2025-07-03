//Print the string in reverse order using function
#include<stdio.h>
#include <string.h>
int rev(char s[],int num)
{
    int i;
    for(i=num-1;i>=0;--i)
    {
        printf("%c",s[i]);
    }
    return 0;
}
int revs(char s[],int num)
{
    int i;
    char c;
    for (i=0;i<num/2;i++)
    {
        c=s[i];
        s[i]=s[num-i-1];
        s[num-i-1]=c;
    }
    printf("%s",s);
}
int main()
{
    int i,num;
    char s[50];
    printf("Haritha\t126018017\n");
    printf("Enter the number of elements : ");
    scanf("%s",s);
    num=strlen(s);
    printf("After reversal : ");
    revs(s,num);
}