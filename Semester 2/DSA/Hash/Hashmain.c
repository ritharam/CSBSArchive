#include<stdio.h>
#include"Hash.h"

int main()
{
  NODE **ht;
  int n,x,m;
  printf("enter the number of rows in hash table:");
  scanf("%d",&n);
  ht=create_hash(n);
  do{
    printf("1-insert\n2-search\n3-exit\n");
    scanf("%d",&m);
    switch(m){
      case 1:
            printf("enter the element to insert:");
            scanf("%d",&x);
            hash_insert(ht,n,x);
            break;
      case 2:
            printf("enter the element to search:");
            scanf("%d",&x);
            hash_search(ht,n,x);
            break;
     default:
            if(m>3){printf("wrong input\n");}
            break;
     }
   }while(m!=3);
   hash_delete(ht,n);
   return 0;
}
