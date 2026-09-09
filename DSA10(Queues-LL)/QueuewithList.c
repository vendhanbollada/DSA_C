//			QueuewithList.c
// Implementation of queue using linked lists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueList.h"

void InitData (QUEUE *mq)
{
	mq->front = NULL;
	mq->rear = NULL;
}

NODE *CreateNode (int data)
{
	NODE *pnode;

	if ((pnode = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("memory allocation failed\n");
		exit (0);
	}
	pnode -> data = data;
	pnode -> next = NULL;
	return pnode;
}

void DisplayQ (QUEUE *mq)
{
	NODE *p_temp;

	for (p_temp = mq->front; p_temp != NULL; p_temp = p_temp->next)
		printf ("Data is %d\n", p_temp->data);
}


void Enqueue (QUEUE *mq, int data)
{
	NODE *pnode = CreateNode (data);

	if (mq->rear == NULL)
	{
		mq->rear = pnode;
		if (mq->front == NULL)
			mq->front = pnode;
	}
	else
	{
		mq->rear->next = pnode;
		mq->rear = pnode;
	}
}

	
int Dequeue (QUEUE *mq)
{
	NODE *p_temp = mq->front;
	int data = INT_MAX;

	if (p_temp != NULL)
	{
		data = p_temp->data;
		mq->front = p_temp->next;
		if (mq->front == NULL)		// Queue is empty now
			mq->rear = NULL;
		free (p_temp);
	}

	else
	{
		printf ("Queue is empty\n");
		mq->front = mq->rear = NULL;
	}
	return (data);
}

bool isEmpty (QUEUE *mq)
{
	bool ret_val = ((mq->front == NULL) && (mq->rear == NULL)) ? true: false;
	return ret_val;
}
	
int Peek (QUEUE *mq)
{
	NODE *p_temp = mq->front;
	int data = INT_MAX;

	if (p_temp != NULL)
		data = p_temp->data;
	return data;
}

void freeList (QUEUE *mq)
{
	NODE *current = mq->front;
	NODE *nextNode;
	while (current != NULL)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}