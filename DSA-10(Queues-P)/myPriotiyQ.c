#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include "priorityq.h"


NODE * newNode(int priotiy , int data){
    NODE * nNode = (NODE*)malloc(sizeof(NODE));
    if(!nNode){
        printf("memory allocation failed\n");
        return NULL;
    }
    nNode->data = data;
    nNode->priority = priority;
    nNode->next = NULL;
return nNode;
}

void InsertNode(NODE **head, int data, int priority)
{
    NODE *pnew = newNode(data, priority);
    if (pnew == NULL)
    {
        return;
    }

    // Case 1: Insert at the head (empty list or strictly higher priority)
    if (*head == NULL || priority < (*head)->priority)
    {
        pnew->next = *head;
        *head = pnew;
        return;
    }

    // Case 2: Traverse to find the insertion point (stop right before it)
    NODE *curr = *head;
    while (curr->next != NULL && curr->next->priority <= priority)
    {
        curr = curr->next;
    }

    pnew->next = curr->next;
    curr->next = pnew;
}

int DeleteNode(NODE **head)
{
    if (*head == NULL)
    {
        return -1;
    }

    NODE *ptemp = *head;
    int data = ptemp->data;

    *head = (*head)->next;
    free(ptemp);

    return data;
}

int peek(NODE **head , int *data , int *priority){
    if(*head == NULL){
        return -1;
    }
*data = (*head)->data;
*priority = (*head)->priority;
return 0;
}

int isEmpty(NODE **head)
{
    return (head == NULL || *head == NULL);
}

void PrintQueue(NODE *head)
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    for (NODE *ptemp = head; ptemp != NULL; ptemp = ptemp->next)
    {
        printf("Priority: %d, Data: %d\n", ptemp->priority, ptemp->data);
    }
}

void freeList(NODE **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    NODE *ptemp = *head;
    while (ptemp != NULL)
    {
        NODE *next_node = ptemp->next;
        free(ptemp);
        ptemp = next_node;
    }

    *head = NULL;
}

