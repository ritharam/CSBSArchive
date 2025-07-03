//Count the vowels, numbers, uppercase letters and lowercase
#include<stdio.h>
#include<string.h>

int uc(char s[],int num)
{   
    int i,upper=0;
    for (i = 0; i < num; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            upper++;
        }
    }
    printf("%d",upper);
    
}

int lc(char s[],int num)
{   
    int i,lower=0;
    for (i = 0; i < num; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lower++;
        }
    }
    printf("%d",lower);
    
}

int num(char s[],int num)
{
    int i,number=0;
    for (i = 0; i < num; i++)
    {
        if (s[i]>= '0' && s[i]<= '9')
        {
            number++;
        }
    }
    printf("%d",number);
}

int vow(char s[],int num)
{
    int i,vowel=0;
    for (i = 0; i < num; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] =='o' || s[i]=='O' || s[i] == 'u' || s[i] == 'U')
        {
            vowel++;
        }
    }
    printf("%d",vowel);
}

int main() 
{   
    int num;
    char s[50];
    printf("Haritha\t126018017\n");
    printf("Enter the string : ");
    scanf("%s",s);
    num=strlen(s);
    printf("Number of uppercases : %d\n",uc(s,num));
    printf("Number of lowercases : %d\n",lc(s,num));
    printf("Number of vowels : %d\n",vow(s,num));
    printf("Number of digits : %d\n",lc(s,num));
}
