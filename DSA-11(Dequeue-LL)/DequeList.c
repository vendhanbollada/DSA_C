// DequeList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DequeList.h"

// Allocates memory for a new node and initializes pointers
NODE *NewNode()
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    temp->next = NULL;
    return temp;
}

// Inserts an element at the front of the deque
void InsertFirst(int item, NODE **pfront, NODE **prear)
{
    NODE *newNode = NewNode();
    newNode->info = item;

    if (*pfront == NULL)
    {
        *pfront = newNode;
        *prear = newNode;
    }
    else
    {
        newNode->next = *pfront;
        *pfront = newNode;
    }
}

// Inserts an element at the rear of the deque (Enqueue)
void Enqueue(int item, NODE **pfront, NODE **prear)
{
    NODE *newNode = NewNode();
    newNode->info = item;

    if (*prear == NULL)
    {
        *pfront = newNode;
        *prear = newNode;
    }
    else
    {
        (*prear)->next = newNode;
        *prear = newNode;
    }
}

// Removes and returns an element from the front (Dequeue)
int Dequeue(NODE **pfront, NODE **prear)
{
    if (*pfront == NULL)
    {
        return INT_MAX;
    }

    NODE *temp = *pfront;
    int data = temp->info;

    if (*pfront == *prear)
    {
        *pfront = NULL;
        *prear = NULL;
    }
    else
    {
        *pfront = (*pfront)->next;
    }

    free(temp);
    return data;
}

// Removes and returns an element from the rear (DeleteLast)
int DeleteLast(NODE **pfront, NODE **prear)
{
    if (*pfront == NULL)
    {
        return INT_MAX;
    }

    NODE *temp = *prear;
    int data = temp->info;

    if (*pfront == *prear)
    {
        *pfront = NULL;
        *prear = NULL;
    }
    else
    {
        NODE *curr = *pfront;
        while (curr->next != *prear)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        *prear = curr;
    }

    free(temp);
    return data;
}

// Displays all elements currently stored in the deque
void PrintList(NODE **pfront)
{
    if (*pfront == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    NODE *curr = *pfront;
    printf("\nDeque elements: ");
    while (curr != NULL)
    {
        printf("%d -> ", curr->info);
        curr = curr->next;
    }
    printf("NULL\n");
}