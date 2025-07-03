typedef struct {
	int N;
	int SN;
	int DN;
	int IN;
	int RA;
}Element;

typedef struct stack
{
	int MAX_SIZE;
	int top;
	Element* S;
} Stack;

void createstack(int n);
int ISFULL();
int ISEMPTY();
void push(Element x);
Element pop();
Element peek();