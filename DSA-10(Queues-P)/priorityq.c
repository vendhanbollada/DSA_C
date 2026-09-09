//			priorityq.c

// C code to implement Priority Queue using Linked List 
#include <stdio.h> 
#include <stdlib.h> 
#include "priorityq.h"
  
// Function to Create A New Node 
NODE* newNode(int d, int p) 
{ 
	NODE* temp = malloc(sizeof(NODE)); 
	if (temp != NULL)
	{
		temp->data = d; 
		temp->priority = p; 
		temp->next = NULL; 
	}
	return temp; 
} 
  
// Return the value at head and the status of the operation
int Peek(NODE** head, int *data, int *priority) 
{ 
	int ret_val = 0;
	if (*head == NULL)
		ret_val = -1;
	else
	{
		*data = (*head) -> data;
		*priority = (*head) -> priority;
	}
	return ret_val;
} 
  
// Removes the element with the highest priority from the list 
int DeleteNode (NODE** head) 
{ 
	int ret_val = -1;
    NODE* temp = *head; 
	if (temp != NULL)
	{
		printf ("Element deleted is %d with priority %d\n", temp->data, temp->priority);
    	(*head) = (*head)->next; 
		ret_val = 0;
		free (temp);
	}
	return ret_val;
} 
  
// Function to insert according to priority 
void InsertNode (NODE** head, int d, int p) 
{ 
	NODE* start = (*head); 

	// Create new Node 
	NODE* temp = newNode(d, p); 

	if (temp == NULL)
	{
		printf ("Unable to create a new node\n");
		exit (1);
	}
  
	if (start != NULL)
	{
		// Special Case: The head of list has lesser priority than
		// new node. So insert new node before head node and change 
		// head node. 
		if ((*head)->priority > p) 
		{ 
			// Insert New Node before head 
			temp->next = *head; 
			(*head) = temp; 
		} 
		else 
		{ 
			// Traverse the list and find a position to insert new node 
			while (start->next != NULL && start->next->priority < p) 
			{ 
				start = start->next; 
			} 

			// Either at the end of the list or at required position 
			temp->next = start->next; 
			start->next = temp; 
		}
	}
	else
		*head = temp;  
} 
  
// Function to check if list is empty 
int isEmpty(NODE** head) 
{ 
    return (*head) == NULL; 
} 
  
// Free the memory taken up by the whole list
void freeList (NODE **head)
{
	NODE *current = *head;
	NODE *nextNode;
	while (current != NULL)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
	*head=NULL;
}

void PrintQueue (NODE *head)
{
	NODE *p_temp;

	for (p_temp = head; p_temp != NULL; p_temp=p_temp->next)
		printf ("Data is %d Priority is %d\n", p_temp->data, 
						p_temp->priority);
}
