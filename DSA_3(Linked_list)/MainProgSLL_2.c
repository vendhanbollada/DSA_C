//				MainProgSLL_2.c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "SLList_2.h"

int main (int argc, char **argv)
{
	char option, sub_opt;
	bool ret_val;
	int count, num;
	NODE *head = NULL;
	
	head = CreateList (head);	// Create the list

	while (1)
	{
		printf ("Select\n: I - Insert\n D - Delete\n S - Search\n P - Print\n M - Modify\n R - Reverse\n E - Empty?\n L - Palindrome?\n C - Count \n Q - Quit:");
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
						head = InsertAtBeginning (head);
					break;

					case 'L':
						head = InsertAtEnd (head);
					break;

					case 'O':
						head = InsertAnywhere (head);
					break;

					default:
						printf ("invalid option\n");
				}
			break;

			case 'M':
				ModifyList (head);
			break;

			case 'L':
			/*
				ret_val = Palindrome ();
				if (ret_val == true)
					printf ("It is a palindrome\n");
				else
					printf ("Not a palindrome\n");
			*/
				printf ("Work in progress\n");
			break;



			case 'D':
				printf ("Sub options: F - First Node L - Last Node O - Any Node:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						head = DeleteFirstNode (head);
					break;

					case 'L':
						head = DeleteLastNode (head);
					break;

					case 'O':
						head = DeleteAnyNode (head);
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

			case 'P':
				 PrintList (head);
			break;

			case 'E':
				if (IsListEmpty (head))
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			case 'R':
				/*
				ReverseList ();
				*/
				printf ("Work in progress\n");
			break;


			case 'C':	// Count and print the number of times a
					// given number appears in the linked list
				printf ("Key in the number:");
				scanf ("%d", &num);
				count = CountandPrint (head, num);
				printf ("The number %d appears %d times\n", num,
							count);
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	head = FreeList (head);
	return 0;
}