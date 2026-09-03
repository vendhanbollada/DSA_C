#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "DLList_2.h"


NODE* CreateNode(){
    if(NODE* newNode = (NODE*)malloc(sizeof(NODE)) == NULL){
        printf("Memory allocation failed");
        exit(0);
    }else{
    printf("Enter the data");
    scanf("%d" , &newNode->data);
    }
    newNode->prev = NULL;
    newNode->next = NULL;   

return newNode;
}

void CreateList(int n, NODE **head, NODE **tail)
{
    if(n <= 0){
      return;
    }
    for (int i = 0; i < n; i++){
        NODE *pNode = CreateNode();

        if (*head == NULL){
            // First node becomes both head and tail
            *head = pNode;
            *tail = pNode;
        }
        else{
            // Append to tail and advance the tail pointer
            (*tail)->next = pNode;
            pNode->prev = *tail;
            *tail = pNode;
        }
    }
}
void InsertAtBeginning (NODE **head){
    NODE *pNode = createNode();
    if(*head == NULL){
        *head = pNode;
        return;
    }
    pNode->next = *head;
    (*head)->prev = pNode;
    *head = pNode;
}

InsertAtEnd(NODE **tail){
    NODE *pNode = createNode();
    if(*tail == NULL){
        *tail = pNode;
        return;
    }
    (*tail)->next = pNode;
    pNode->prev = *tail;
    *tail = pNode; 
}

void InsertAnywhere(NODE **head, NODE **tail)
{
    int pos;
    printf("Enter the position to insert at: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    // Case 1: Beginning
    if (pos == 1)
    {
        InsertAtBeginning(head);
        // If the list was empty before insertion, tail must also point to head
        if (*tail == NULL)
        {
            *tail = *head;
        }
        return;
    }

    // Traverse to find the (pos - 1)-th node
    NODE *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Out of bounds check
    if (temp == NULL)
    {
        printf("Invalid position (out of bounds)\n");
        return;
    }

    // Case 2: End
    if (temp == *tail)
    {
        InsertAtEnd(tail);
        return;
    }

    // Case 3: Middle
    NODE *pNode = CreateNode();
    pNode->next = temp->next;
    pNode->prev = temp;
    temp->next->prev = pNode;
    temp->next = pNode;
}

void DeleteFirstNode(NODE **head, NODE **tail)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE *temp = *head;

    // Case 1: Only one node in the list
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    // Case 2: Multiple nodes
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);
}

void DeleteLastNode(NODE ** head , NODE ** tail){
    if(*head == NULL){
        printf("list is empty");
        return;
    }

    NODE *temp = *tail;

    if(*head =+ *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
free(temp);
}
void DeleteAnyNode(NODE **head, NODE **tail)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    // Case 1: First node
    if (pos == 1)
    {
        DeleteFirstNode(head, tail);
        return;
    }

    // Traverse directly to the target node at 'pos'
    NODE *temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Out of bounds check
    if (temp == NULL)
    {
        printf("Invalid position (out of bounds)\n");
        return;
    }

    // Case 2: Last node
    if (temp == *tail)
    {
        DeleteLastNode(head, tail);
        return;
    }

    // Case 3: Middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void PrintList(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    for (NODE *temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}
void ReversePrint(NODE *tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    for (NODE *temp = tail; temp != NULL; temp = temp->prev)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}
bool IsListEmpty (NODE *head){
    return (head == NULL) ? true : false
}

void FreeList(NODE **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    while (*head != NULL)
    {
        NODE *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

bool SearchList(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to search.\n");
        return false;
    }

    int target;
    printf("Enter the value you want to find: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid input.\n");
        return false;
    }

    // Traverse until the pointer itself runs off the end (becomes NULL)
    for (NODE *pTemp = head; pTemp != NULL; pTemp = pTemp->next)
    {
        if (pTemp->data == target)
        {
            return true; // Match found
        }
    }

    return false; // Traversed the entire list, value not found
}

void ModifyList(NODE **head){
    if(head == NULL)
    {
        printf("List is empty, nothing to search.\n");
        return ;
    }

    int target;
    printf("Enter the value you want to find: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid input.\n");
        return ;
    }

    // Traverse until the pointer itself runs off the end (becomes NULL)
    for (NODE *pTemp = head; pTemp != NULL; pTemp = pTemp->next)
    {
        if (pTemp->data == target)
        {
            int value;
            printf("enter the changed value");
             if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input.\n");
                    return;
                }else{
                    pTemp->data = value;
                    printf("Value updated successfully.\n");
                    return;
                }
        }
    }
    printf("Value %d not found in the list.\n", target);
}

void Navigate(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to navigate.\n");
        return;
    }

    NODE *pCurrent = head;
    char cmd;

    while (1)
    {
        printf("\n--- Current Node: [%d] ---\n", pCurrent->data);
        printf("[F]orward | [B]ackward | [Q]uit\nCommand: ");
        
        if (scanf(" %c", &cmd) != 1)
        {
            break;
        }

        switch (toupper((unsigned char)cmd))
        {
            case 'F':
                if (pCurrent->next != NULL)
                {
                    pCurrent = pCurrent->next;
                }
                else
                {
                    printf("Already at TAIL. Cannot move forward.\n");
                }
                break;

            case 'B':
                if (pCurrent->prev != NULL)
                {
                    pCurrent = pCurrent->prev;
                }
                else
                {
                    printf("Already at HEAD. Cannot move backward.\n");
                }
                break;

            case 'Q':
                printf("Exiting navigation.\n");
                return;

            default:
                printf("Invalid command. Use F, B, or Q.\n");
                break;
        }
    }
}

