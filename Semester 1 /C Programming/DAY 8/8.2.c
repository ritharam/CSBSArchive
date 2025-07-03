//Players detail using structure 
#include<stdio.h> 
struct play 
{
    char name[25]; 
    int age; 
    int nmatch; 
    int run; 
    float avgrun; 
}cri[100],t; 

void main() 
{ 
    int n,i,j; 
    float d;
    printf("Haritha\t126018017\n");
    printf("Enter number of players : ");
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    { 
        printf("Enter name,age,no of matches,total runs\n"); 
        scanf("%s%d%d%d",cri[i].name,&cri[i].age,&cri[i].nmatch,&cri[i].run); 
    } 
    for(i=0;i<n;i++) 
    {
        cri[i].avgrun=cri[i].run/cri[i].nmatch;
    } 
    for(i=0;i<n;i++) 
    {
        for(j=i+1;j<n;j++) 
        { 
            if(cri[i].avgrun>cri[j].avgrun) 
            {
                t=cri[i]; 
                cri[i]=cri[j]; 
                cri[j]=t;
            }
        } 
    } 
    printf("\nDetails in ascending order\n"); 
    printf("\nName\tage\tmatches\truns\tavg_run"); 
    for(i=0;i<n;i++) 
    {
        printf("\n%s\t%d\t%d\t%d\t%f",cri[i].name,cri[i].age,cri[i].nmatch,cri[i].run,cri[i].avgrun);
    } 
}