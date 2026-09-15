//				DequeListMain.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "DequeList.h"


int main ()
{
	int data, choice;
	NODE *front = NULL;
	NODE *rear = NULL;
	while(1)
	{
		printf("\n1.Enqueue(InsertLast)\n2.Dequeue(DeleteFirst)\n3.Insert First\n4.Delete Last\n5.Display\n6.Exit\n");
		printf("\nEnter your choice:");
		choice = getch ();
		if (choice == '6')
			break;
		switch(choice)
		{
		case '1':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			Enqueue(data, &front, &rear);
		break;
		case '2':
			data = Dequeue (&front, &rear);
			if (data != INT_MAX)
				printf ("\nData removed is %d\n", data);
		break;
        	case '3':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			InsertFirst (data, &front, &rear);
		break;
		case '4':
			data = DeleteLast (&front, &rear);
			if (data == INT_MAX)
				printf ("\nQueue is empty\n");
			else
				printf ("\nData removed is %d\n", data);
		break;
		case '5':
			PrintList (&front);
		break;
	
		default:
			printf("\nEnter a valid choice");
		break;
		}
	}
	return 0;
}
