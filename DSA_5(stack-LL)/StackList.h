//		StackList.h

typedef struct node
{
	int data;
	struct node *next;
} NODE;


int StackSize(NODE *p_head);
void CreateStack (NODE **);
void push (NODE **);
int pop (NODE **);
int peek (NODE **);
void PrintStack (NODE *);
void InsertAtBeginning (NODE **);
int DeleteLatestEntry (NODE **);
bool IsStackEmpty (NODE *);
void FreeStack (NODE **);
void reverseWord (NODE *, char *, char *);
