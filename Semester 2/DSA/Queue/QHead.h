typedef int Element;
typedef struct Queue
{
	int MAX_SIZE;
	int front;
	int rear;	
	Element* S;
} Queue;

void createqueue(int n);
int ISFULL();
int ISEMPTY();
void ENQ(Element x);
Element DEQ();
void multiENQ(char fname[]);
void multiDEQ(char fname[], int m);
