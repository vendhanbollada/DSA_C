//			MainProgDLL_2.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "DLList_2.h"

int main (int argc, char **argv)
{
	char option, sub_opt;
	bool ret_val;
	int numNodes;
	NODE *head = NULL;
	NODE *tail = NULL;
	
	if (argc < 2)
	{
		printf ("Usage %s <Number>\n", argv [0]);
		exit (0);
	}
	numNodes = atoi (argv[1]);
	
	CreateList(numNodes, &head, &tail);	// Create the list

	while (1)
	{
		printf ("Select: I - Insert D - Delete S - Search P - Print M - Modify E - Empty? N - Navigate Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option)
		{
			case 'I':
				printf ("Sub options: F - First Node L - Last Node O - Others:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						InsertAtBeginning (&head);
					break;

					case 'L':
						InsertAtEnd (&tail);
					break;

					case 'O':
						InsertAnywhere (&head, &tail);
					break;

					default:
						printf ("invalid option\n");
				}
			break;

			case 'M':
				ModifyList (&head);
			break;


			case 'D':
				printf ("Sub options: F - First Node L - Last Node O - Any Node:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						DeleteFirstNode (&head, &tail);
					break;

					case 'L':
						DeleteLastNode (&head, &tail);
					break;

					case 'O':
						DeleteAnyNode (&head, &tail);
					break;

					default:
						printf ("invalid option\n");
				}

			break;

			case 'S':
				if (SearchList (head) == true)
					printf ("Element found\n");
				else
					printf ("Element not found\n");
			break;

			case 'N':
				NavigateList (&head, &tail);
			break;

			case 'P':
				printf ("Sub options: F - Forward R - Reverse:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						PrintList (head);
					break;

					case 'R':
						ReversePrint (tail);
					break;
					default:
						printf ("Invalid option\n");
				}
			break;

			case 'E':
				if (IsListEmpty (head))
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	FreeList (&head);
	return 0;
}