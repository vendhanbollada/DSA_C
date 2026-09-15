#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "DequeList.h"


NODE *NewNode()
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL; // or exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

int Dequeue(NODE ** front , NODE **rear ){
    if(*front == NULL || front == NULL){
        printf("the list is empty , nothing to delete");
        return INT_MAX;
    }
    
}

int DeleteLast(NODE ** head , NODE * tail){

}

void InsertFirst(int item, NODE **head, NODE **tail)
{
    NODE *pNode = NewNode();
    if (pNode == NULL)
        return;

    pNode->info = item;

    if (*head == NULL) // Case 1: Empty deque
    {
        *head = pNode;
        *tail = pNode;
    }
    else               // Case 2: 1 or more nodes present
    {
        pNode->next = *head;
        *head = pNode;
    }
}

void PrintList(NODE ** head){
    if(*head == NULL || head == NULL){
        printf("the list is empty");
        return;
    }
    for(NODE * ptemp = *head ; ptemp != NULL ; ptemp = ptemp->next){
        printf("%d" , ptemp->info);
    }
printf("End");
}

int DeleteLast(NODE **head, NODE **tail)
{
    if (head == NULL || *head == NULL)
    {
        return INT_MAX;
    }

    NODE *temp = *tail;
    int data = temp->info;

    // Case 1: Only 1 node present
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    // Case 2: Multi-node traversal
    else
    {
        NODE *curr = *head;
        while (curr->next != *tail)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        *tail = curr;
    }

    free(temp);
    return data;
}

void Enqueue(int data, NODE **front, NODE **rear)
{
    NODE *pNode = NewNode();
    if (pNode == NULL)
    {
        return;
    }
    pNode->info = data;

    // Case 1: Empty Queue
    if (*front == NULL)
    {
        *front = pNode;
        *rear = pNode;
    }
    // Case 2: 1 or more nodes present (O(1) direct hook via *rear)
    else
    {
        (*rear)->next = pNode;
        *rear = pNode;
    }
}

int Dequeue(NODE **front, NODE **rear)
{
    if (front == NULL || *front == NULL)
    {
        return INT_MAX;
    }

    NODE *ptemp = *front;
    int data = ptemp->info;

    // Case 1: Exactly 1 node left
    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    // Case 2: Multi-node removal
    else
    {
        *front = (*front)->next;
    }

    free(ptemp);
    return data;
}
