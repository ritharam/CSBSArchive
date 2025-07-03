//Count the occurrences of each element.
//Create an array CLEAR without any duplicate values.
#include<stdio.h>
int main()
{
    int x=0,f=1,k,j,i, num, a[50],CLEAR[50],count;
    printf("Haritha R\t126018017\n");
    printf("Enter the number of elements : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<num;i++)
    {
        f=1;
        count=0;
        for (k=0;k<=x;k++)
        {
            if(a[i]==CLEAR[k])
            {
                printf("Occurences : %d\n",a[i]);
                f=0;
                break;
            }
        }

        if(f==1)
        {
            CLEAR[x]=a[i];
            x++;
            printf("Original : %d\n",a[i]);

            for(j=0;j<num;j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                }
            }  
            printf("%d %d\n",a[i],count);
        }
    }
    printf("Elements after clearing duplicates : ");
    for(i=0;i<x;i++)
    {
        printf("%d ",CLEAR[i]);
    }
    
}
