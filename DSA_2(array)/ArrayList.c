//		ArrayList.c

// Implementation of a static list using arrays
// We will use array of integers for simplicity
// We can use an array of any type including array of structures

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrayList.h"

#define MAX_SIZE 	100

static int cur_max;	// Indicates the number of elements in the list
static int list [MAX_SIZE];

// Create a list of a given number of elements
void CreateList ()
{
	printf ("Enter the number of elements to be added in the list:\t");
	scanf ("%d", &cur_max);
	printf ("Enter the array elements:\t");
	for (int i = 0;i < cur_max; i++)
		scanf ("%d", &list[i]);
}

bool IsListEmpty ()
{
	bool ret_val = false;
	if (cur_max == 0)
		ret_val = true;
	return ret_val;
}


// Insert an element into the list
bool Insert()
{
	int data, pos, ret_val = true;
	
	printf ("Enter the data to be inserted:");
	scanf ("%d", &data);
	printf ("Enter the position at which element has to be inserted:");
	scanf ("%d", &pos);
	if (pos >= MAX_SIZE || pos < 0)
	{
		printf ("Invalid position");
		ret_val = false;
	}
	else
	{
		if (pos > (cur_max + 1))	// preventing empty spaces
			pos = cur_max + 1;
		for(int i = cur_max - 1 ; i >= pos - 1 ; i--)
			list [i + 1] = list [i];

		list [pos - 1] = data;
		cur_max += 1;
	}
	return ret_val;
}

// The deletion operation
void Delete ()
{
	int i, pos ;
 	printf ("\nEnter the position of the data to be deleted:\t");
	scanf ("%d", &pos);
	
	if (pos < 0 || pos > cur_max)
	{
		printf ("Invalid position\n");
		return;
	}
	else
	{
		printf ("The data deleted is: %d\n", list[pos-1]);
		for (i = pos - 1;i < cur_max - 1; i ++)
			list [i] = list[i + 1];
		cur_max = cur_max - 1;
	}
}

bool Modify ()
{
	int pos, newVal;
	bool ret_val = true;

	printf ("The position of the element to be modified:");
	scanf ("%d", &pos);
	if (pos < 0 || pos > cur_max)
	{
		printf ("Invalid position\n");
		ret_val = false;;
	}

	else
	{
		printf ("Key in the new value:");
		scanf ("%d", &newVal);
		list [pos - 1] = newVal;
	}
	return ret_val;
}


// Display the values of the elements in the array
void Display()
{
	int i;
	printf("\n**********Elements in the array**********\n");
	for (i = 0;i < cur_max; i++)
		printf ("%d\t", list[i]);
	printf ("\n");
}

// Search for an element in the list
void Search()
{
	int search;
	bool found = false;
	printf("\nEnter the element to be searched:\t");
	scanf ("%d", &search);
	for (int i = 0;i < cur_max; i++)
	{
 		if(search == list[i])
		{
			found = true;
			break;
		}
	}
	found == true ? printf("\nElement present in the list\n"):
			printf("\nElement not present in the list\n");
}

