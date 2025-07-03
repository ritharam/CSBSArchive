//Decimal to binary, decimal to octal and decimal to hexadecimal by creating individual recursions.
#include <stdio.h>
int dtb(int n)
{
    if (n == 0) 
    {
        return 0;
    }
    dtb(n / 2);
    printf("%d", n % 2);
}
int dto(int n)
{
    if (n == 0) 
    {
        return 0;
    }
    dto(n / 8);
    printf("%d", n % 8);
}
int dth(int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    dth(n / 16);
    char H[] = "0123456789ABCDEF";
    printf("%c",H[n%16]);
}
int main(void)
{
    int n;
    printf("Haritha\t126018017\n");
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary number %d : %d\n", n,dtb(n));
    printf("Octal number %d : %d\n", n,dto(n));
    printf("Hexadecimal number %d : ", n);
    dth(n);
    return 0;
}