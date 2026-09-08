//		CircularQ.h

// Array, rear pointer, max size, data
void Enqueue (int *, int *, int, int);

// Array, pointer to front, maximum size, pointer to data
int Dequeue (int *, int *, int, int *);	// Return the first value and remove it

// Array, max size, front, pointer to data
int Peek (int *, int, int, int *);	// Return the first value, keep it in the q

// Array, Max size
bool isFull (int *, int);		// Check whether queue is full

// Array, Max size
bool isEmpty (int *, int);		// Check whether queue is empty

// Array, front, rear and max size
void displayQ (int *, int, int, int);	// Display the contents of the queue

// Array, max size
void printArray (int *, int);		// Blindly prints the array elements