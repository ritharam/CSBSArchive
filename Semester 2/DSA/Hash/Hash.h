typedef struct node{
   int data;
   struct node *link;
}NODE;

NODE **create_hash(int n);
void hash_insert(NODE **ht, int n,int x);
void hash_search(NODE **ht, int n,int x);
void hash_delete(NODE **ht, int n);
