//		QueueList.h

typedef struct node
{
	int data;
	struct node *next;
} NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
} QUEUE;

void InitData (QUEUE *);
void Enqueue (QUEUE *, int);
int Dequeue (QUEUE *);		// Return the first value and remove it
int Peek (QUEUE *);		// Return the first value, keep it in the q
bool isEmpty (QUEUE *);	// Check whether queue is empty
void DisplayQ (QUEUE *);
void freeList (QUEUE *);