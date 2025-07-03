// Arithmatic calculator in Switch case
#include <stdio.h>
int main()
{   int a,b,add,sub,mul,div,mod,ch;
    printf("Haritha R\t126018017\n");
    printf("Enter two numbers:");
    scanf("%d%d",&a,&b);
    printf("Enter \n1.Addition\n2.Subtraction\n3.Product\n4.Quotient\n5.Remainder\n");
    scanf("%d",&ch);
    switch(ch)
    {case 1:
    add=a+b;
    printf("Addition of %d and %d =%d\n",a,b,add); break;
    case 2:
    sub=a-b;
    printf("Subtraction of %d and %d =%d\n",a,b,sub);break;
    case 3:
    mul=a*b;
    printf("Product of %d and %d =%d\n",a,b,mul);break;
    case 4:
    div=a/b;
    printf("Qoutient of %d and %d =%d\n",a,b,div);break;
    case 5:
    mod=a%b;
    printf("Remainder of %d and %d =%d\n",a,b,mod);break;
}
return 0;
}
