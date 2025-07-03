//Count the vowels, numbers, uppercase letters and lowercase letters by creating individual recursion.
#include <stdio.h>
#include <ctype.h>
int vow(char *str)
{
    if (*str == '\0')
        return 0;
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
        *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
        return 1 + vow(str + 1);
    else
        return vow(str + 1);
}

int dig(char *str)
{
    if (*str == '\0')
        return 0;

    if (isdigit(*str))
        return 1 + dig(str + 1);
    else
        return dig(str + 1);
}

int uc(char *str)
{
    if (*str == '\0')
        return 0;

    if (isupper(*str))
        return 1 + uc(str + 1);
    else
        return uc(str + 1);
}

int lc(char *str)
{
    if (*str == '\0')
        return 0;

    if (islower(*str))
        return 1 + lc(str + 1);
    else
        return lc(str+1);
}

int main()
{
    char str[100];
    printf("Haritha\t126018017\n");
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Number of vowels: %d\n", vow(str));
    printf("Number of numbers: %d\n", dig(str));
    printf("Number of uppercase letters: %d\n", uc(str));
    printf("Number of lowercase letters: %d\n", lc(str));
    return 0;
}


