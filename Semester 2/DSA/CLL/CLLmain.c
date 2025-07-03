#include<stdio.h>
#include"CLL.h"

int main(){
    int op,x,y;
    CDLL P;
    P=createCDLL();
    do{
        printf("\n1)Insert\n2)Search\n3)Delete\n4)Display\n");
        printf("Enter your choice :");
        scanf("%d",&op);
        switch(op){
            case 1:
            printf("Enter the Element to Insert :");
            scanf("%d",&x);
            insertCDLL(&P,x); break;
            case 2:
            printf("Enter the Element to Search :");
            scanf("%d",&x);
            y = searchCDLL(&P,x);
            if(y!=-1) printf("The Element was found in %d Postion",y);
            else printf("Element Not found");
            break;
            case 3:
            printf("Enter the Element to Delete :");
            scanf("%d",&x);
            deleteCDLL(&P,x); break;
            case 4: display(&P); break;
        }
    }
    while(op<5);
    return 0;
}