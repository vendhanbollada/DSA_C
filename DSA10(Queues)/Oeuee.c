#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueList.h"

void InitData (QUEUE *mq){
    mq->front = NULL;
    mq->rear = NULL;
}

NODE *CreateNode(int data)
{
    NODE *pnode = (NODE *)malloc(sizeof(NODE));
    if (pnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL; // or exit(EXIT_FAILURE);
    }
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}
void Enqueue(QUEUE *mq, int data)
{
    NODE *pnode = CreateNode(data);

    // Case 1: Empty Queue
    if (mq->rear == NULL)
    {
        mq->front = pnode;
        mq->rear = pnode;
    }
    // Case 2: Queue has 1 or more nodes
    else
    {
        mq->rear->next = pnode; // link old rear to new node
        mq->rear = pnode;       // move rear pointer to new node
    }
}

int Dequeue(QUEUE *mq)
{
    if (mq->front == NULL)
    {
        printf("Queue is empty\n");
        return INT_MAX;
    }

    NODE *ptemp = mq->front;
    int data = ptemp->data;

    mq->front = mq->front->next;

    // If the queue just became empty, ground rear too
    if (mq->front == NULL)
    {
        mq->rear = NULL;
    }

    free(ptemp);
    return data;
}

int Peek(QUEUE *mq){
    if(mq->front == NULL){
        printf("the list is empty");
        return INT_MAX ;
    }
    return mq->fornt->data;
}

bool isEmpty(QUEUE *mq){
    return mq->rear == NULL;
}

void DisplayQ(QUEUE *mq)
{
    NODE *p_temp = mq->front;

    while (p_temp != NULL)
    {
        printf("Data is %d\n", p_temp->data);
        p_temp = p_temp->next;
    }
}

void freeList(QUEUE *mq)
{
    NODE *current = mq->front;
    NODE *nextNode;

    while (current != NULL)
    {
        nextNode = current->next; // Save address of next node
        free(current);            // Safe to free now
        current = nextNode;       // Advance to next
    }

    mq->front = NULL;
    mq->rear = NULL;
}