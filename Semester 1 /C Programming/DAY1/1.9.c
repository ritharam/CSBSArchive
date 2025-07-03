//GRoss Salary
#include<stdio.h>
int main()
{
    int GS,BP,DA,HRA,TRA;
    printf("Haritha R\t126018017\n");
    printf("Enter Basic pay:");
    scanf("%d", &BP);
    DA=(17*BP)/100;
    HRA=(10*BP)/100;
    TRA=(25*DA)/100;
    GS=BP+DA+HRA+TRA;
    printf("Gross Salary : %d",GS);
}
