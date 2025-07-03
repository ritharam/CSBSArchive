#include<stdio.h>
#include"dllhead.h"

int main(){
	int op,x,pos;
	DLLNODE *head;
	head = createDLL();
	do{
	printf("\n1-insert\n2-delete\n3-search\n4-displatFtoL\n5-displayLtof\n6-exit :");
	scanf("%d",&op);
	switch(op){
		case 1:
		printf("Enter the element to insert :");
		scanf("%d",&x);
		insertODLL(head,x);
		break;
		case 2:
		printf("Enter the element to delete :");
		scanf("%d",&x);
		deleteODLL(head,x);
		break;
		case 3:
		printf("Enter the element to search :");
		scanf("%d",&x);
		pos = searchODLL(head,x);
		if(pos!=-1){printf("The element %d is found at %d position",x,pos);}
		else{printf("Element %d not found",x);}
		break;
		case 4:
		display_FTOL(head);
		break;
		case 5:
		display_LTOF(head);
		break;
		case 6:
		printf("Exitting the DLL");
		break;
		default:
		printf("INVALID SELECTION!!");
		break;}}
	while(op<7);
	return 0;
}
