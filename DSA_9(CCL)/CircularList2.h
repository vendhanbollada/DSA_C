//		CircularList2.h

typedef struct node
{
	int data;
	struct node *next;
} NODE;

void CreateList (NODE **, NODE **, int);
void InsertAtBeginning (NODE **, NODE **);
void InsertAtEnd (NODE **, NODE **);
void InsertAnywhere (NODE **, NODE **);
void DeleteFirstNode (NODE **, NODE **);
void DeleteLastNode (NODE **, NODE **);
void DeleteAnyNode (NODE **, NODE **);
void Navigate (NODE *, NODE *);
void ModifyList (NODE *);
bool SearchList (NODE *);
void PrintList (NODE **);
bool IsListEmpty (NODE *);
void FreeList (NODE **);