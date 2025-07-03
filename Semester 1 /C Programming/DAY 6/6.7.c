//Matrix addition and Multiplication.
#include<stdio.h>    
int main()
{
    int r1,r2,c1,c2;
    printf("Haritha R\t126018017\n");
    printf("Enter number of rows for First Matrix:\n");    
    scanf("%d",&r1);    
    printf("Enter number of columns for First Matrix:\n");     
    scanf("%d",&c1); 
    printf("Enter number of rows for Second Matrix:\n");    
    scanf("%d",&r2);    
    printf("Enter number of columns for Second Matrix:\n"); scanf("%d",&c2);
    int add[r1][c2];
    int mul[r1][c2];
    int m1[r1][c1],m2[r2][c2];
    printf("Enter first matrix elements \n");    
    for(int i=0;i<r1;i++)    
    {    
        for(int j=0;j<c1;j++)    
        {    
            scanf("%d",&m1[i][j]);    
        }    
    }    
    printf("Enter Second matrix elements\n");    
    for(int i=0;i<r2;i++)    
    {    
        for(int j=0;j<c2;j++)    
            {    
                scanf("%d",&m2[i][j]);    
            }    
    }
    printf("Matrix Addition\n");
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c1; ++j) 
        {
            add[i][j] = m1[i][j] + m2[i][j];
        }
    }
    for(int i=0;i<r1;i++)    
    {    
        for(int j=0;j<c2;j++)    
        {    
            printf("%d\t",add[i][j]);    
        }    
        printf("\n");    
    }
    printf("Multiplied matrix\n");
    for(int i=0;i<r1;i++)    
        {    
            for(int j=0;j<c2;j++)    
            {    
                mul[i][j]=0; 
                for(int k=0;k<c1;k++)    
                {    
                    mul[i][j]+=m1[i][k]*m2[k][j];    
                } 
            }    
        }     
    for(int i=0;i<r1;i++)    
    {    
        for(int j=0;j<c2;j++)    
        {    
            printf("%d\t",mul[i][j]);    
        }    
        printf("\n");    
    } 
    return 0;  
}
