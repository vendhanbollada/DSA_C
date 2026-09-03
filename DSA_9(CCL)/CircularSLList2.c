//				CircularSLList2.c

// Implementation of a singly linked list (dynamic)
// All possible error conditions are not fully handled 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "CircularList2.h"

int ListSize (NODE *p_head)
{
	int count = 0;
	NODE *p_node = p_head;

	if (p_head != NULL)
	{
		while (1)
		{
			count ++;
			p_node = p_node -> next;
			if (p_node == p_head)
				break;
		}
	}
	else
		printf ("Empty list\n");
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

void DisplayNode (NODE *p_node)
{
	if (p_node != NULL)
		printf ("Data is %d\n", p_node->data);
}


void Navigate (NODE *p_head, NODE *p_tail)
{
	char sub_opt;
	NODE *p_node = p_head;
	bool go_on = true;

	while (1)
	{
		printf ("Select: N - Next F - First L - Last: R - Return:");
		scanf (" %c", &sub_opt);
		sub_opt = toupper (sub_opt);
		switch (sub_opt)
		{
			case 'F':
				p_node = p_head;
			break;

			case 'L':
				p_node = p_tail;
			break;

			case 'N':
				p_node = p_node -> next;
			break;

			case 'R':
				go_on = false;
			break;

			default:
				printf ("Invalid option\n");
		}
		if (go_on == false)
			break;
		DisplayNode (p_node);
	}
} 


void ModifyList (NODE *pp_head)
{
	NODE *p_head = pp_head;
	int pos, val;
	NODE *p_temp = p_head;
	int lSize = ListSize (p_head);

	printf ("Number of the node you want to modify:");
	scanf ("%d", &pos);
	if (pos > 0 && pos <= lSize)
	{
		printf ("The new value:");
		scanf ("%d", &val);

		for (int i = 0; i < (pos - 1); i ++)
			p_temp = p_temp -> next;
		p_temp->data = val;
	}
	else
		printf ("Invalid position\n");
}


void CreateList (NODE **pp_head, NODE **pp_tail, int num)
{
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;
	NODE *p_node, *p_temp;

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		
		if (p_head == NULL)
			p_head = p_tail = p_node;
		else
		{
			p_tail -> next = p_node;
			p_tail = p_node;
		}
		p_tail -> next = p_head;
	}
	*pp_head = p_head;
	*pp_tail = p_tail;	
}


void PrintList (NODE **pp_head)
{
	NODE *p_head = *pp_head;
	NODE *p_node;

	if (p_head != NULL)
	{
		p_node = p_head;
		while (1)
		{
			printf ("Val is %d\n", p_node->data);
			p_node = p_node -> next;
			if (p_node == p_head)	
			// Last node is linked to the first node
				break;
		}
	}
	else
		printf ("List is empty\n");
}


void InsertAtBeginning (NODE **pp_head, NODE **pp_tail)
{
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;
	NODE *p_node;

	p_node = CreateNode ();
	p_node -> next = p_head;
	p_head = p_node;
	p_tail -> next = p_head;
	*pp_head = p_head;
	*pp_tail = p_tail;
}

void InsertAtEnd (NODE **pp_head, NODE **pp_tail)
{
	NODE *p_node;
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;

	p_node = CreateNode ();
	
	p_tail -> next = p_node;
	p_tail = p_node;
	p_tail -> next = p_head;
	*pp_head = p_head;
	*pp_tail = p_tail;
}

void InsertAnywhere (NODE **pp_head, NODE **pp_tail)
{
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;
	int pos;
	int listLen;
	NODE *p_temp = p_head, *p_prev, *p_node;

	listLen = ListSize (p_head);
	printf ("Position at which to insert:");
	scanf ("%d", &pos);

	if (pos < 1 || pos > listLen)
	{
		printf ("Invalid position\n");
		return;
	}
	if (pos > 1 && pos <= listLen)
	{
		if (pos == 1)
			InsertAtBeginning (pp_head, pp_tail);
		else if (pos == listLen)
			InsertAtEnd (pp_head, pp_tail);
		else
		{
			for (int i = 0; p_temp != NULL; 
					p_prev = p_temp, p_temp = p_temp->next, i++)
			{
				if (i == (pos - 1))
				{
					p_node = CreateNode ();
					p_prev -> next = p_node;
					p_node -> next = p_temp;
					break;
				}
			}
		}
	}
	else
		printf ("Invalid position\n");
}


bool SearchList (NODE *p_head)
{
	NODE *p_temp;
	int value;
	bool found = false;
	bool go_on = true;

	printf ("What are you looking for?:");
	scanf ("%d", &value);
	if (p_head != NULL)
	{
		p_temp = p_head;
		while (go_on)
		{
			if (p_temp -> data != value)
			{
				p_temp = p_temp -> next;
				if (p_temp == p_head)
					go_on = false;
			}
			else
			{
				found = true;
				break;
			}
		}
	}
	return found; 
}

void DeleteFirstNode (NODE **pp_head, NODE **pp_tail)
{
	NODE *p_temp;
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;

	if (p_head != NULL)
	{
		p_temp = p_head;
		if (p_head->next != NULL)	// More than one node in the list
		{
			p_head = p_head -> next;
			p_tail -> next = p_head;
		}
		else
			p_head = p_tail = NULL;
		free (p_temp);
	}
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
	*pp_tail = p_tail;
}

void DeleteLastNode (NODE **pp_head, NODE **pp_tail)
{
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;
	NODE *curr, *prev = NULL;
	if (p_head != NULL)
	{
		// If the list has only one node, delete it.
		if (p_head->next == NULL)
		{ 
			free(p_head);
			p_head = p_tail = NULL;
		}
		else
		{
			for (curr = p_head; curr != p_tail; 
					prev = curr, curr = curr -> next)
				;
			p_tail = prev;
			p_tail -> next = p_head;
			free  (curr);
		}
	}							 
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
	*pp_tail = p_tail;
}

void DeleteAnyNode (NODE **pp_head, NODE **pp_tail)
{
	int nodeNum, i;
	NODE *p_head = *pp_head;
	NODE *p_tail = *pp_tail;
	int lsize = ListSize (p_head);
	NODE *p_cur, *p_prev;

	printf ("Enter the number of the node you want to delete:");
	scanf ("%d", &nodeNum);

	if (nodeNum > 0 && nodeNum <= lsize)
	{
		if (nodeNum == 1)	// Delete first node
			DeleteFirstNode (pp_head, pp_tail);

		else if (nodeNum == lsize)	// Last node to be deleted
			DeleteLastNode (pp_head, pp_tail);

		else
		{
			p_cur = p_head;
			for (i = 0; i < (nodeNum - 1); i ++, p_prev = p_cur, p_cur = p_cur -> next)
				;
			p_prev -> next = p_cur -> next;
			free (p_cur);
		}
	}
	else
		printf ("Invalid position\n");
}



bool IsListEmpty (NODE *p_head)
{
	return (p_head == NULL);
}

// Free the memory taken up by the whole list
void FreeList (NODE **pp_head)
{
	NODE *p_head = *pp_head;
	NODE *current = p_head;
	NODE *nextNode;
	while (1)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
		if (current == p_head)
			break;
	}
}