//			StackMain_2.c - Implementation using array

#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <ctype.h>
#include "StackOps_2.h"

int main (int argc, char **argv)  
{  
	STACK *myStack;
	char choice;
	int data;
	bool retVal;
	
	printf ("Stack implementation using array\n");  
    
	myStack = initStack ();
	if (myStack != NULL)
	{
		while (1)
		{
			printf ("Choose  P: Push O - Pop E - Peek M -Empty F - Full T - Print Q - quit: ");
			
			scanf (" %c", &choice);
			choice = toupper (choice);
			if (choice == 'Q')
				break;

			// Taking user input for the operation to be performed
			switch (choice)
			{
				case 'P':	// Push operation
					printf ("Key in the data to be pushed:");
					scanf ("%d", &data);
					push (myStack, data);
				break;

				case 'O':	// Pop operation
					data = pop (myStack);
					printf ("Popped out value is %d\n", data);
				break;

				case 'E':	// Peek operation
					data = peek (myStack);
					printf ("The value at the top is %d\n", data);
				break;

				case 'M':	// Is the stack empty:
					retVal = isEmpty (myStack);
					if (retVal == true)
						printf ("Stack is empty\n");
					else
						printf ("Stack is not empty\n");
				break;
				
				case 'F':	// Is the stack full:
					retVal = isFull (myStack);
					if (retVal == true)
						printf ("Stack is full\n");
					else
						printf ("Stack is not full\n");
				break;
				
				case 'T':
					printStack (myStack);
				break;

				default:
					printf ("Invalid option\n");	
				break;

			}
		}
	}
	else
		printf ("cannot allocate memory to the stack\n");
	return 0;
}
