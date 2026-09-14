// Deque implementation in C using (non-circular) array

//			DequeArrayMain.c


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "DeqArray.h"

int main (int argc, char **argv) 
{
	int front = -1, rear = -1;
	int i;
	int capacity, data;
	int *int_queue;
 	char choice;

	if (argc < 2)
	{
		printf ("Usage: %s <MaxCapacity>\n", argv[0]);
		exit (0);
	}

	capacity = atoi (argv [1]);
	printf ("Capacity is %d\n", capacity);

	if ((int_queue = (int *) malloc (capacity * sizeof (int))) == NULL)
	{
		printf ("malloc failed\n");
		exit (0);
	}

	for (i = 0; i < capacity; i++)
    		int_queue [i] = -INT_MAX;

	do
	{
		printf ("Key in your option: \nF - Add at the Front \n B - Add at the Rear\n D - Delete from Front \n K - Delete from Rear \n N - Display front element \n R - Display rear element \n P - Display All \n Q - Quit:");
		scanf (" %c", &choice);
		choice = toupper (choice);
		if (choice == 'Q')
			break;
		
		switch (choice)
		{
			case 'F':	// Add at the front
				printf ("Key in the data to be added:");	
				scanf ("%d", &data);
				addFront (int_queue, data, &front, &rear, capacity);
			break;

			case 'B':	// Add at the rear end
				printf ("Key in the data to be added:");	
				scanf ("%d", &data);
				addRear (int_queue, data, &front, &rear, capacity);
			break;

			case 'D':	// Delete from the front
				delFront(int_queue, &front, &rear);
			break;

			case 'K':	// Delete from the back
				delRear (int_queue, &front, &rear);
			break;

			case 'N':	// Display the element at the front
				data = frontEle(int_queue, front);
				printf ("The front element is %d\n", data);
			break; 

			case 'R':	// Display the element at the Rear
				data = rearEle(int_queue, rear);
				printf ("The rear element is %d\n", data);
			break;
			
			case 'P':	// Display everything in the array
				display (int_queue, capacity);
			break;

			default:
				printf ("Invalid choice\n");
		}
	} while (1);
	free (int_queue);
}

