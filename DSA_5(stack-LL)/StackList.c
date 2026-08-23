//				StackList.c

// Implementation of stack using a singly linked list
// All possible error conditions are not fully handled 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "StackList.h"

int StackSize (NODE *p_head)
{
	int count = 0;
	NODE *p_node = p_head;

	for (count = 0; p_node != NULL; p_node = p_node->next)
		count ++;
	return count;
}

// Creates a node; allocates memory, gets the data value, etc
NODE *CreateNode ()
{
 	NODE *p_node;
	if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (0);		
	}
	p_node -> next = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void CreateStack (NODE **pp_head)
{
	int num, val;
	NODE *p_node, *p_temp, *p_head;

	p_head = *pp_head;
	printf ("How many items do you want to push?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		if (p_head != NULL)
			p_node -> next = p_head;
		p_head = p_node;
	}
	*pp_head = p_head;
}


void PrintStack (NODE *p_head)
{
	NODE *p_node;

	for (p_node = p_head; p_node != NULL; p_node = p_node->next)
		printf ("Val is %d\n", p_node->data);
}

void push (NODE **pp_head)
{
	InsertAtBeginning (pp_head);
}

// pop will pop out the entry at the top of the list
int pop (NODE **pp_head)
{
	DeleteLatestEntry (pp_head);
}

int peek (NODE **pp_head)
{
	NODE *p_head = *pp_head;
	int lEntry = INT_MAX;

	if (p_head != NULL)
	{
		lEntry = p_head->data;
		printf ("Entry at the top is %d\n", p_head->data);
	}
	return lEntry;
}


void InsertAtBeginning (NODE **pp_head)
{
	NODE *p_node;
	NODE *p_head = *pp_head;

	p_node = CreateNode ();
	p_node -> next = p_head;
	p_head = p_node;
	*pp_head = p_head;
}


int DeleteLatestEntry (NODE **pp_head)
{
	NODE *p_temp;
	NODE *p_head = *pp_head;
	int lEntry = INT_MAX;

	if (p_head != NULL)
	{
		p_temp = p_head;
		lEntry = p_temp->data;
		p_head = p_head -> next;
		free (p_temp);
	}
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
	return lEntry;
}


bool IsStackEmpty (NODE *p_head)
{
	bool ret_val;

	ret_val = p_head == NULL ? true: false;
	return ret_val;
}


// Free the memory taken up by the whole list
void FreeStack(NODE **pp_head)
{
    	NODE *current = *pp_head;
    	NODE *nextNode;
    	while (current != NULL)
    	{
			nextNode = current->next;
        	free(current);
        	current = nextNode;
    	}
    	*pp_head=NULL;
}

/*

Incomplete implementation
void reverseWord (NODE *head, char *inStr, char *outStr)
{
	int slen = strlen (inStr);
	int count;
	
	for (count = 0; count < slen; count ++)
		push (&head, inStr[count]);
	
	for (count = 0; count < slen; count ++)
		outStr [count] = (char) pop (&head);
	outStr [count] = '\0';
	
	printf ("The reversed string is %s\n", outStr);
}
*/