#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"CircularList2.h"

NODE *CreateNode()
{
 	NODE *p_node;
	if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (1);		
	}
	p_node -> next = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void CreateList(NODE **head, NODE **tail, int n)
{
    if (n <= 0)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }
    NODE *pNode = NULL;
    NODE *pTemp = NULL;
    for (int i = 0; i < n; i++)
    {
        pNode = CreateNode();

        if (*head == NULL)
        {
            *head = pNode;
            pTemp = pNode;
        }
        else
        {
            pTemp->next = pNode;
            pTemp = pNode;
        }
    }

    // Bind the circular reference and update the tail
    *tail = pTemp;
    (*tail)->next = *head; // The circle closes here
}

void InsertAtBeginning(NODE ** head , NODE ** tail){
    NODE* pNode = NULL;
    pNode = createNode();
    if(*head == NULL){
        *head = pNode;
        *tail = pNode;
        pNode->next = pNode;
    }else{
        (*tail)->next = pNode;
        pNode->next = *head;
        *head =pNode;
    }
}

void InsertAtEnd(NODE ** head , NODE ** tail){
    NODE* pNode = NULL;
    pNode = createNode();
    if(*head == NULL){
        *head = pNode;
        *tail = pNode;
        pNode->next = pNode;
    }else{
        (*tail)->next = pNode;
        pNode->next = *head;
        *tail =pNode;
    }
}

void InsertAnywhere(NODE** head , NODE** tail){
    for(*head = pTemp ; pNode = *tail ; pTemp = pTemp->next);
    printf("enter the location of ");
    NODE* pNode;
}

void DeleteFirstNode(NODE ** head , NODE ** tail){
    if(*head == NULL){
        printf("list is empty , Nothing to delete");
        return;
    }
    NODE* pTemp = *head;
    if(*head = *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        *head = (*head)->next;
        (*tail)->next = *head;
    }
free(pTemp);
}

void DeleteLastNode(NODE **head , NODE **tail){
    if(*tail == NULL){
        printf("list is empty , Nothing to delete");
        return;
    }
    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        for(NODE* pTemp2 ; pTemp2->next->next != *tail ; pTemp2 = pTemp2->next);
            free(pTemp2->next);
            pTemp2->next = *head;
    }
}

bool IsListEmpty(NODE *head){
    return head == NULL;
}

void PrintList(NODE **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE *pTemp = *head;
    for (; pTemp->next != *head; pTemp = pTemp->next)
    {
        printf("%d -> ", pTemp->data);
    }
    // Print the last node (tail)
    printf("%d -> (head)\n", pTemp->data);
}

void FreeList(NODE **head)
{
    if (*head == NULL)
    {
        return;
    }

    NODE *pCurrent = *head;
    NODE *pNext = NULL;

    do
    {
        pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    } while (pCurrent != *head);

    *head = NULL;
}

void InsertAnywhere(NODE **head, NODE **tail)
{
    int pos;
    printf("Enter position (1-based): ");
    if (scanf("%d", &pos) != 1 || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    // Case 1: Inserting at the very beginning
    if (pos == 1)
    {
        InsertAtBeginning(head, tail);
        return;
    }

    // If pos > 1 but list is empty, it's out of bounds
    if (*head == NULL)
    {
        printf("List is empty, cannot insert at position %d\n", pos);
        return;
    }

    // Step to the node at position (pos - 1)
    NODE *pTemp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        pTemp = pTemp->next;
        // If we wrapped back around to head, pos exceeds length + 1
        if (pTemp == *head)
        {
            printf("Position out of range\n");
            return;
        }
    }

    // Case 2: Inserting right after tail (new last node)
    if (pTemp == *tail)
    {
        InsertAtEnd(head, tail);
        return;
    }

    // Case 3: Inserting strictly in the middle
    NODE *pNode = CreateNode();
    pNode->next = pTemp->next;
    pTemp->next = pNode;
}