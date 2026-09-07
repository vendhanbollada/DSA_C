//		CircularDLList.h

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

void DisplayNode (NODE *);
void CreateList (NODE **, NODE **, int);
void InsertAtBeginning (NODE **, NODE **);
void InsertAtEnd (NODE **, NODE **);
void InsertAnywhere (NODE **, NODE **);
void DeleteFirstNode (NODE **, NODE **);
void DeleteLastNode (NODE **, NODE **);
void DeleteAnyNode (NODE **, NODE **);
void NavigateList (NODE *, NODE *);
void ModifyList (NODE *);
bool SearchList (NODE *);
void PrintList (NODE *);
void ReversePrint (NODE *);
bool IsListEmpty (NODE *);
void FreeList (NODE **, NODE **);
