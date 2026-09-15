//			CircularQueue.c
// Implementation of circular queue using arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "CircularQ.h"

static bool overWritten = false;

void displayQ (int myqueue [], int front, int rear, int max_size)
{
	if (!overWritten)	
	{
		for (int i = front; i < rear; i ++)
		{
			printf (" %d ", myqueue [i]);
		}
		printf ("\n");
	}
	else	// Some overwriting has taken place
	{
		int i = front;
		while (1)
		{
			printf (" %d ", myqueue [i]);
			i = (i + 1) % max_size;
			if (i == rear)
				break;
		}
		printf ("\n");
	}
}

void Enqueue (int myQueue [], int *p_rear, int max_size, int data)
{
	int rear = *p_rear;

#ifdef DEBUG
	printf ("Inside Enquque rear is %d\n", rear);
#endif
	myQueue [rear] = data;
	if (!overWritten)
	{
		if ((rear + 1) == max_size)
			overWritten = true;
		
	}
	rear = (rear + 1) % max_size;
	*p_rear = rear;
}
		
int Dequeue (int myQueue [], int *p_front, int max_size, int *data)
{
	int front = *p_front;
	int retVal = 0;

	if (isEmpty (myQueue, max_size))
	{
		printf ("There is nothing to read\n");
		retVal = -1;
	}

	else
	{
		*data = myQueue [front];
		myQueue [front] = -INT_MAX;
		front = (front + 1) % max_size;
		*p_front = front;
	}
	return retVal;
}

bool isEmpty (int myQueue [], int max_size)
{
	bool ret_val = true;

	for (int i = 0; i < max_size; i ++)
		if (myQueue [i] != -INT_MAX)
		{
			ret_val = false;
			break;
		}
	return ret_val;
}
	
bool isFull (int myQueue [], int max_size)
{
	bool ret_val = true;

	for (int i = 0; i < max_size; i ++)
		if (myQueue [i] == -INT_MAX)
		{
			ret_val = false;
			break;
		}
	return ret_val;
}

int Peek (int myQueue [], int max_size, int front, int *data)
{
	int retVal = 0;
	if (isEmpty (myQueue, max_size))
	{
		printf ("Queue is empty\n");
		retVal = -1;
	}
	else
		*data = myQueue [front];
	return retVal;
}

void printArray (int myQueue [], int maxSize)
{
	for (int i = 0; i < maxSize; i ++)
		printf ("Element %d is %d\n", i + 1, myQueue [i]);
}
