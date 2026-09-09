//			QueueListMain.c
// Implementation of queue using linked lists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueList.h"

int main (int argc, char *argv[])
{
	int ret_val, data;
	char choice;
	QUEUE mq;

	InitData (&mq);
	do
	{
		printf ("Key in your option: N - Enque D - Deque S - Display P - peek E - Empty? Q - Quit:");
		scanf (" %c", &choice);
		choice = toupper (choice);
		if (choice == 'Q')
			break;
		switch (choice)
		{
			case 'N':	// Enque op
				printf ("Key in the data to be added:");	
				scanf ("%d", &data);
				Enqueue (&mq, data);
			break;

			case 'D':	// Deque op
				data = Dequeue (&mq);
				if (data != INT_MAX)
					printf ("Data removed is %d\n", data);
			break;

			case 'P':	// Peek op
				data = Peek (&mq);
				if (data != INT_MAX)
					printf ("Data at the top is %d\n", data);
				else
					printf ("The list is empty\n");

			break;

			case 'E':	// Is the queue empty
				ret_val = isEmpty (&mq);
				if (ret_val)
					printf ("Queue is empty\n");
				else
					printf ("Queue is not empty\n");

			break;

			case 'S':	// Show or display list
				DisplayQ (&mq);
			break;

			default:
				printf ("Invalid choice\n");
		}
	} while (1);
	freeList (&mq);
}

