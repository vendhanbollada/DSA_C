//		SLList_2.h

typedef struct node
{
	int data;
	struct node *next;
} NODE;

// NODE *CopyList (NODE *);
NODE *CreateNode ();//over
NODE *CreateList (NODE *);//over
int ListSize (NODE *);//over
NODE *InsertAtBeginning (NODE *);//over
NODE *InsertAtEnd (NODE *);//over
NODE *InsertAnywhere (NODE *);//over
NODE *DeleteFirstNode (NODE *);//over
NODE *DeleteLastNode (NODE *);//over
NODE *DeleteAnyNode (NODE *);//over
void ModifyList (NODE *);
bool SearchList (NODE *);
void PrintList (NODE *);//over
bool IsListEmpty (NODE *);//over
// void ReverseList (NODE *);
NODE *FreeList (NODE *);//over
// bool Palindrome (NODE *);
int CountandPrint (NODE *, int);