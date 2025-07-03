typedef struct adjlist{
	int adjver;
	struct adjlist *link;
}NODE;

typedef struct vtable{
	char name[20];
	int nav;
	NODE *adjptr;
}vertex;

int constructgraph(vertex G[]);
void displaygraph(vertex G[],int n);
void storegraph(vertex G[],int n, char fname[]);
int loadgraph(vertex G[], char fname[]);
	
