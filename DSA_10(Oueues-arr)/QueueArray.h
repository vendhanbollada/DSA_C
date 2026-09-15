//		QueueArray.h

// Array, pointer to rear, max size and data
void Enqueue (int *, int *, int, int); 

// Array, pointer to front, pointer to rear, max size, pointer to return data
int Dequeue (int *, int *, int *, int *);	// Return the first value and remove it

// Array, front, rear, pointer to return data
int Peek (int *, int, int, int *);	// Return the first value, keep it in the q

// rear, max size
bool isFull (int, int);		// Check whether queue is full

// front, rear, max_size
bool isEmpty (int, int, int);		// Check whether queue is empty


// Array, front, rear
void ShowNodes (int *, int, int);