// Arithmatic calculator in functions
#include <stdio.h>
int add(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int main()
{
    char op;
    int a,b,ans;
    printf("Enter two numbers : ");
    scanf("%d%d", &a,&b);
    printf("Choose the operator : ");
    scanf("%s",&op);
    switch(op)
    {   case '+': ans = add(a,b);break;
        case '-': ans = sub(a,b);break;
        case '*': ans = mul(a,b);break;
        case '/': ans = div(a,b);break;
        default : printf("Invalid operator");
    }
    printf("%d %c %d = %d", a,op,b,ans);
    return 0;
}
int add(a,b)
    {return a+b;}
int sub(a,b)
    {return a-b;}
int mul(a,b)
    {return a*b;}
int div(a,b)
    {return a/b;}
