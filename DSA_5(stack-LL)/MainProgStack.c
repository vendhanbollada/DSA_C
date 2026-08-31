//			MainProgStack.c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "StackList.h"

int main ()
{
	char option;
	int poppedVal, peekVal;
	NODE *head = NULL;
	char oStr [50], rStr [50];
	
	CreateStack (&head);	// Create the stack

	while (1)
	{
		printf ("Select\n: P - Push\n O - Pop\n E - Peek\n T - Print\n M - Empty?\n R - Reverse Word \n Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option)
		{
			case 'P':		// Push
				push (&head);
			break;

			case 'O':		// Pop
				poppedVal = pop (&head);
				if (poppedVal != INT_MAX)
					printf ("The popped val is %d\n", poppedVal);
			break;

			case 'E':		// Peek
				peekVal = peek (&head);
				printf ("The val at the top of the list is %d\n", peekVal);
			break;

			case 'M':		// Empty ?
				if (IsStackEmpty (head))
					printf ("Stack is empty\n");
				else
					printf ("Stack is not empty\n");
			break;

			case 'T':		// Print
				 PrintStack (head);
			break;

			case 'R':	// Reverse a given word
				printf ("Input the word to be reversed:");
				scanf (" %s", oStr);
				reverseWord (head, oStr, rStr);
				printf ("The reversed string is %s\n", rStr);
			break;


			default:
				printf ("Invalid option\n");
		}
	}
	FreeStack (&head);
	return 0;
}