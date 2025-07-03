//Data types with its memory size and address. 
#include <stdio.h>
int main() 
{
    int a; float b; char c; double d;
    printf("Haritha R\t126018017\n");
    printf("Size of integer : %d, float : %d, character : %d, double : %d\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));
    printf("Address of integer : %d, float : %d, character : %d, double : %d",&a,&b,&c,&d);
    return 0;
}
