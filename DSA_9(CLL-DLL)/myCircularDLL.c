#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"CircularDLList.h"

// 1. Allocates and wires circular pointers to self
NODE *CreateNode(int data)
{
    NODE *pnode = (NODE *)malloc(sizeof(NODE));
    if (!pnode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    pnode->data = data;
    pnode->next = pnode; // Circular invariant
    pnode->prev = pnode; // Circular invariant

    return pnode;
}

// 2. Handles the console input main forced onto you
NODE *GetNodeFromUser(void)
{
    int data;
    printf("Enter the data: ");
    if (scanf("%d", &data) != 1)
    {
        printf("Invalid input\n");
        return NULL;
    }

    // Calls the first function here!
    return CreateNode(data);
}

// the above implementation is good beacuse it tackle two problem speartely instead of toegether

void PrintList(NODE *head){
    if(!head){
        printf("there is nothing to display");
    }
    printf("%d", pnode->)
    for(NODE * pnode->next = head ; pnode != head ; pnode = pnode->next){
        printf("%d" , pnode->data);
    }
    return; 
}

/*void PrintList(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE *pnode = head;
    do
    {
        printf("%d -> ", pnode->data);
        pnode = pnode->next;
    } while (pnode != head);

    printf("(head)\n");
}*/
//better implementation

void DisplayNode(NODE *pnode)
{
    if (pnode == NULL)
    {
        printf("Node is NULL\n");
        return;
    }
    printf("Data: %d (Prev: %d, Next: %d)\n", 
           pnode->data, pnode->prev->data, pnode->next->data);
}

void CreateList(NODE **head, NODE **tail, int n)
{
    if (n <= 0)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        NODE *pnode = GetNodeFromUser();
        if (!pnode)
            return;

        // First node scenario
        if (*head == NULL)
        {
            *head = pnode;
            *tail = pnode;
            // A 1-node circular list points to itself in both directions
            pnode->next = pnode;
            pnode->prev = pnode;
        }
        // Appending subsequent nodes
        else
        {
            pnode->prev = *tail;
            pnode->next = *head;

            (*tail)->next = pnode;
            (*head)->prev = pnode;

            *tail = pnode; // Update tail to the new node
        }
    }
}


InsertAtBeginning(NODE ** head , NODE ** tail){
    NODE *pnode = GetNodeFromUser();
        if (*head == NULL)
        {
            *head = pnode;
            *tail = pnode;
            // A 1-node circular list points to itself in both directions
            pnode->next = *head;
            pnode->prev = *tail;
        }
    else{
        pnode->next = *head;
        (*tail)->next = pnode;

        (*tail)->next = pnode;
        (*head)->prev = pnode;

        *head = pnode;
    }
}

void InsertAtEnd (NODE ** head, NODE ** tail){
    NODE *pnode = GetNodeFromUser();
    if(*head == NULL){
        *head = pnode;
        *tail = pnode;

        pnode->next = *head;
        pnode->prev = *tail;
    }
    else{
        pnode->next = *head;
        (*tail)->next = pnode;

        (*tail)->next = pnode;
        (*head)->prev = pnode;

        *tail = pnode;
    }
}

DeleteFirstNode(NODE ** head , NODE **tail){
    if(*head == NULL){
        printf("nothing to delete, the list is empty");
        return;
    }

    NODE *ptemp = *head;

    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        *head = ptemp->next;
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }
free(ptemp);
}

void DeleteLastNode(NODE **head , NODE **tail){
    if(*head == NULL){
        printf("nothing to delete , the list is empty");
        return;
    }
    
    NODE *ptemp = *tail;

    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        *tail = ptemp->prev;
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }
free(ptemp);
}

void InsertAnywhere(NODE **head, NODE **tail)
{
    if (*head == NULL)
    {
        printf("List is empty. Inserting at beginning.\n");
        InsertAtBeginning(head, tail);
        return;
    }

    int location;
    printf("Enter the location: ");
    if (scanf("%d", &location) != 1 || location < 1)
    {
        printf("Invalid location\n");
        return;
    }

    if (location == 1)
    {
        InsertAtBeginning(head, tail);
        return;
    }

    // Traverse to the node at index (location - 1)
    NODE *curr = *head;
    for (int i = 1; i < location - 1; i++)
    {
        curr = curr->next;
        if (curr == *head) // Wrapped around: position is beyond list size
        {
            printf("Location exceeds list bounds\n");
            return;
        }
    }

    // If target position is immediately after tail, delegate to InsertAtEnd
    if (curr == *tail)
    {
        InsertAtEnd(head, tail);
        return;
    }

    NODE *pnode = GetNodeFromUser();
    if (!pnode)
        return;

    // Squeeze pnode between curr and curr->next
    pnode->next = curr->next;
    pnode->prev = curr;
    curr->next->prev = pnode;
    curr->next = pnode;
}
//read this again 

bool IsListEmpty(NODE *head){
    return !head;
}

void ReversePrint (NODE *tail){

    if(tail == NULL){
        printf("the list is empty");
        return; 
    }
    NODE *ptemp = tail;
    do{
        printf("%d" , ptemp->data);
        ptemp = ptemp->prev;
    }while(ptemp != tail);

}

void searchList(NODE *head){
    
}