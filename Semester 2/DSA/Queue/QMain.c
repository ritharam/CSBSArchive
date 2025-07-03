#include "QHead.h"
#include<stdio.h>
#include<stdlib.h>

int main () {
    int op,m;
    Element x;
    char fname[25],g;
    createqueue(5);
    do{
        printf("\n1....ENQUEUE\n2....DEQUEUE\n3....Multi ENQUEUE\n4....Multi DEQUEUE\n5....EXIT\n");
        printf("Enter your Choice :");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter the Element to ENQUEUE :");
                scanf("%d", &x);
                ENQ(x);
                break;
            case 2:
                x = DEQ();
                if( x!=-1) printf("The Element DEQUEUED is : %d",x);
                else printf("Queue is empty cannot DEQUEUE");
                break;
            case 3:
                printf("Enter the File Name :");
                scanf("%s", fname);
                multiENQ(fname);
                break;
            case 4:
                scanf("%c",&g);
                printf("Enter the File Name :");
                gets(fname);
                printf("Enter the number of elements to DEQUEUE :");
                scanf("%d",&m);
                multiDEQ(fname,m);
            case 5:
            break;
            break;
            default:
            printf("Enter your choice between 1 to 5 only..."); 
            break;
        }}
    while (op<5); 
    return 0;
}
