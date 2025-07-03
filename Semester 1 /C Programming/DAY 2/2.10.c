// Gross Salary
#include<stdio.h>
int main()
{int GS,BP,DA,HRA,TRA;
printf("Haritha R\t126018017\n");
printf("Enter Basic pay:");
scanf("%d", &BP);
if(BP>=25000)
{DA=(17*BP)/100;
HRA=(10*BP)/100;
TRA=(25*DA)/100;
GS=BP+DA+HRA+TRA;}
else if(BP<25000 && BP>=15000)
{DA=(20*BP)/100;
HRA=(25*BP)/100;
TRA=(50*DA)/100;
GS=BP+DA+HRA+TRA;}
else
{DA=(30*BP)/100;
HRA=(35*BP)/100;
TRA=(75*DA)/100;
GS=BP+DA+HRA+TRA;}
printf("Grosss Salary:%d",GS);}
