#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "DLList_2.h"


NODE *CreateNode ()
{
 	NODE *p_node;
	if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (0);		
	}
	p_node -> next = NULL;
    p_node->prev = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void CreateList (int numNodes, NODE ** head , NODE **tail){
    NODE * p_temp , *p_head , *p_tail , *p_node;
    *head = p_head;
    for(int i = 0 ; i < numNodes ; i++){
        p_node = CreateNode();
            if(p_head == NULL)
               p_head = *tail = *head = p_node;
            else{
                for(p_temp = p_head ; p_temp->next != NULL ; p_temp = p_temp->next){}
                    p_temp->next = p_node;
                    p_node->prev = p_temp;
                    p_tail = p_node;
        }

    }
    *head = p_head;
    *tail = p_tail;
}

void InsertAtBeginning (NODE ** head){
    NODE *p_head = *head;
    NODE *p_node = CreateNode();
    p_head->next = p_node;
    p_node = p_head;
*head = p_head;
}

void InsertAtEnd(NODE** tail){
    NODE *p_node , *p_tail;
    p_tail = *tail;
    p_node = CreateNode();
    p_tail->next =p_node;
    p_tail = p_node;
*tail = p_tail;
}

void PrintList (NODE * head){
    if(head == NULL)
        printf("the list is empty");
    for(NODE * p_temp = head ; p_temp != NULL ; p_temp = p_temp->next){
        printf("%d" , p_temp->data);
    }
}

void ReversePrint (NODE *tail){
    if(tail == NULL)
        printf("the list is empty");
    for(NODE* p_temp = tail ; p_temp != NULL ; p_temp = p_temp = p_temp->prev)   {
        printf("%d" , p_temp->data);
    }
}

void InsertAnywhere(NODE ** head, NODE **tail){
    int location;
    printf("enter the number you want to keep");
    scanf("%d" , &location);
    NODE *p_head = *head , *p_tail = *tail , *p_node , *p_temp;
    for(int i = 0 ; i < location ; i++){
        p_temp = p_head;
       p_temp = p_temp->next;
    }
    p_temp->next = p_node;
    p_node->prev = p_temp;
    *head = p_head;

}

NavigateList(NODE ** head, NODE **tail){
    int option;
    NODE *p_head = *head , *p_tail = *tail;
    printf("1. go to the next node\n2. go to the previous node\n3. go to the first node\n4. go to the last node\n5. exit");
    scanf("%d" , &option);
while(option != 5){
    switch(option){
        case 1:
            if(p_head->next != NULL)
                p_head = p_head->next;
                DisplayNode(p_head);
            else
                printf("you are at the end of the list");
            break;
        case 2:
            if(p_head->prev != NULL)
                p_head = p_head->prev;
                DisplayNode(p_head);
            else
                printf("you are at the beginning of the list");
            break;
        case 3:
            p_head = *head;
            DisplayNode(p_head);
            break;
        case 4:
            p_head = *tail;
            DisplayNode(p_head);
            break;
        case 5:
            return;
        default:
            printf("invalid option");
    }
}

DisplayNode(NODE * node){
    printf("the value of the node is %d" , node->data);
}


DeleteFirstNode(NODE ** head, NODE **tail){
    NODE *p_head = *head , *p_tail = *tail;
    if(p_head == NULL)
        printf("the list is empty");
    else{
        p_head = p_head->next;
        free(p_head->prev);
        p_head->prev = NULL;
    }
    *head = p_head;
}

DeleteLastNode(NODE ** head, NODE **tail){
    NODE *p_head = *head , *p_tail = *tail;
    if(p_tail == NULL)
        printf("the list is empty");
    else{
        p_tail = p_tail->prev;
        free(p_tail->next);
        p_tail->next = NULL;
    }
    *tail = p_tail;
}

deleteAnyNode(NODE ** head, NODE **tail){
    int location;
    printf("enter the location of the node you want to delete");
    scanf("%d" , &location);
    NODE *p_head = *head , *p_tail = *tail , *p_temp;
    for(int i = 0 ; i < location ; i++){
        p_temp = p_head;
        p_temp = p_temp->next;
    }
    p_temp->prev->next = p_temp->next;
    p_temp->next->prev = p_temp->prev;
    free(p_temp);
    *head = p_head;
}

