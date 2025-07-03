#include<stdio.h>
#include<stdlib.h>
#include"CLL.h"

CDLL createCDLL(){
    CDLL P;
    P.first = P.last = NULL;
    return P;
}

void insertCDLL(CDLL *P,int x){
    NODE *T = malloc(sizeof(NODE));
    T->data = x;
    T->next = T->prev = NULL;
    if(P->first == NULL){
        P->first = P->last = T;
        T->prev = T->next = T;
    }
    else if(P->first->data > x){
        P->last = T;
        T->next = P->first;
        T->prev = P->last;
        P->first->prev = T;
        P->first = T;
    }
    NODE *cur = P->first;
    while(cur->next != P->first && cur->data < x){
        cur = cur->next;
    }
    cur->next->prev = T;
    T->next = cur->next;
    T->prev = cur;
    cur->next = T;
    if(cur == P->last) P->last = T;
}

void deleteCDLL(CDLL *P,int x){
    if(P->first == NULL || P->first->data > x) printf("Element Not Found");
    NODE *temp = P->first;
    while(temp->next != P->first && temp->data < x) temp = temp->next;
    if(P->first == P->last == temp) P->first = P->last = NULL;
    else{
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        if(temp == P->first) P->first = P->first->next;
        if(temp == P->last) P->last = P->last->prev;}
}

int searchCDLL(CDLL *P,int x){
    NODE *temp = P->first;
    int count = 0;
    while(temp->next != P->first && temp->data < x){
        if(temp->data == x) return x;
        count++;
        temp= temp->next;
    }
    if(temp->data == x) return x;
    return -1;
}

void display(CDLL *P){
    if(P->first == NULL) printf("Empty");
    NODE *T = P->first;
    while(T->next != P->first){
        printf("%d ",T->data);
        T =T->next;
    }
    printf("%d",P->last->data);  
}