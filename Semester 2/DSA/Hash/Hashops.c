#include<stdio.h>
#include<stdlib.h>
#include"Hash.h"

NODE **create_hash(int n){
    NODE **ht;
    ht=(NODE**)calloc(sizeof(NODE*),n);
    return ht;      
}

void hash_insert(NODE **ht,int n,int x){
     int r=x%n;
     NODE *T=(NODE*)malloc(sizeof(NODE));
     T->data=x;
     T->link= NULL;
     if(ht[r]==NULL) ht[r]=T;
     else{    
     T->link=ht[r];
     ht[r]=T;
     }
}

void hash_search(NODE **ht,int n,int x){
         int r=x%n;
         NODE *temp=ht[r];
         int p=1;
         while(temp!=NULL){
            if(temp->data==x){
                printf("%d is present in %d location and position is %d\n",x,r,p);
                return;
            }
            temp=temp->link;
            p++;
         }
         printf("Element %d is not found ",x);
}

void hash_delete(NODE **ht,int n){
         NODE *T;
         for(int i=0;i<n;i++){
             NODE *temp=ht[i];
             while(temp!=NULL){
                T=temp;
                temp=temp->link;
                free(T);
             }    
         }
}
