//		DLList_2.h

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;


void DisplayNode (NODE *);
void CreateList (int, NODE **, NODE **);
void InsertAtBeginning (NODE **);
void InsertAtEnd (NODE **);
void InsertAnywhere (NODE **, NODE **);
void DeleteFirstNode (NODE **, NODE **);
void DeleteLastNode (NODE **, NODE **);
void DeleteAnyNode (NODE **, NODE **);
void NavigateList (NODE **, NODE **);
void ModifyList (NODE **);
bool SearchList (NODE *);
void PrintList (NODE *);	// Need to pass the head
void ReversePrint (NODE *);	// Need to pass the tail
bool IsListEmpty (NODE *);
void FreeList (NODE **);
