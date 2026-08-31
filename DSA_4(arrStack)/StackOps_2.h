#define STACK_SIZE	100

typedef struct stack
{
	int members [STACK_SIZE];
	int top;
} STACK;


// Function declarations
// Initialize the stack
STACK *initStack(void);

// Check if the stack is full - return true if full, false otherwise
bool isFull(STACK *);

// Check if the stack is empty - return true if emptyy, false otherwise
bool isEmpty(STACK *);

// Push an element onto the stack
void push(STACK *, int);

// Pop an element from the stack
// return -1 if the stack is empty, else the popped value
int pop(STACK *);

// Returns the member at the top without removing it from the stack
int peek(STACK *);

// Prints the members of the stack
void printStack (STACK *);
