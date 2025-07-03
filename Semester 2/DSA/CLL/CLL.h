typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}NODE;

typedef struct list{
    NODE *first;
    NODE *last;
}CDLL;

CDLL createCDLL();
void insertCDLL(CDLL *P,int x);
void deleteCDLL(CDLL *P,int x);
int searchCDLL(CDLL *P,int x);
void display(CDLL *P);

