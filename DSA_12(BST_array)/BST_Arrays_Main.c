//			BST_Arrays_Main.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include "BST_Arrays.h"

int main(int argc, char **argv) 
{
	// storing the maximum number of nodes
	int max_nodes;
	char value;
	char *tree = NULL;
	char choice;
	bool notOver = true;

  	if (argc < 2)
	{
		printf ("Usage: %s <Number>\n", argv[0]);
		exit (0);
	}
	
	max_nodes = atoi (argv[1]);
	// array to store the tree

	if ((tree = (char *) malloc (max_nodes)) == NULL)
	{
		printf ("malloc failed\n");
		exit (0);
	}

	for (int i = 0; i < max_nodes ; i ++)
		tree [i] = -CHAR_MAX;	

	while (notOver)
	{
		printf ("i - insert\n p - preorder\n n - inorder\n o - postorder\n d - Dump\n q - quit:");
		scanf (" %c", &choice);
		choice = toupper (choice);
		switch (choice)
		{
			case 'I':	
				printf ("What value do you want to insert (0 - 127):");
				scanf (" %c", &value);
				insert (tree, max_nodes, value);
			break;
						
			case 'P':
				preorder (tree, 0, max_nodes);
				printf ("\n");
			break;
			
			case 'D':
				dumpArray (tree, max_nodes);
			break;
						
			case 'N':
				inorder (tree, 0, max_nodes);
				printf ("\n");
			break;

			case 'O':
				postorder (tree, 0, max_nodes);
				printf ("\n");
			break;
			
			case 'Q':
				notOver = false;
			break;
			default:
				printf ("Invalid option\n");
		}
	}
	return 0;
}
