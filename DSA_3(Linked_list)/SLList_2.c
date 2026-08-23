#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "SLList_2.h"

NODE* CreateNode(){
    NODE* p_node = (NODE*)malloc(sizeof(NODE));
    if(p_node==NULL){
        prinft("UNable to create node: memory not available");
        exit(0);
    }
    p_node->next=NULL;
    printf("key in the value:");
    scanf("%d",&p_node->data);
    return p_node;
}
NODE *CreateList (NODE *head){
    int num,val;
    NODE* p_node,*p_temp;
    printf("How many nodes do you want?");
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        p_node= CreateNode();
        if(head==NULL){
            head=p_node;
        }
        else{
            for(p_temp=head;p_temp->next!=NULL;p_temp=p_temp->next){
                p_temp->next=p_node;
            }
        }
    }
    return head;
}
void PrintList (NODE *head){
    NODE* temp = head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int ListSize (NODE *head){
    NODE* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

NODE *InsertAtBeginning (NODE *head){
    NODE* p_node;
    p_node=CreateNode();
    p_node->next=head;
    head=p_node;
    return head;
}

NODE *InsertAtEnd (NODE *head){
    NODE * p_temp , * p_node;
    p_node = CreateNode();
    for(p_temp = head ; p_temp->next != NULL ; p_temp = p_temp->next);
    p_temp->next = p_node;
return head;
}

bool IsListEmpty (NODE *head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}

NODE *InsertAnywhere(NODE *head)
{
    int pos;
    printf("Enter the position where you want to insert the node: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return head;
    }
    NODE *p_node = CreateNode();
    if (pos == 1){
        p_node->next = head;
        return p_node;
    }
    NODE *p_temp = head;
    for (int i = 1; i < pos - 1; i++){
        if (p_temp == NULL){
            printf("Position out of range.\n");
            return head;
        }
        p_temp = p_temp->next;
    }

    if (p_temp == NULL){
        printf("Position out of range.\n");
        return head;
    }
    p_node->next = p_temp->next;
    p_temp->next = p_node;
    return head;
}


NODE *DeleteFirstNode (NODE *head){
    NODE* p_temp;
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    p_temp = head;
    head = p_temp->next;
    free(p_temp);
return head;
}

NODE *DeleteLastNode(NODE *head)
{
    NODE *p_temp, *s_temp;
    if (head == NULL){
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    for (p_temp = head; p_temp->next->next != NULL; p_temp = p_temp->next);
    s_temp = p_temp->next;
    free(s_temp);
    p_temp->next = NULL;
    return head;
}

NODE *FreeList(NODE *head)
{
    NODE *p_temp;
    while (head != NULL)
    {
        p_temp = head;
        head = head->next;
        free(p_temp);
    }
    return NULL;
}

NODE *DeleteAnyNode(NODE *head)
{
    int pos;
    printf("Enter the position of the node you want to delete: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if (pos == 1)
    {
        NODE *p_temp = head;
        head = head->next;
        free(p_temp);
        return head;
    }
    NODE *p_temp = head;
    NODE *s_temp;
    for (int i = 1; i < pos - 1; i++)
        p_temp = p_temp->next;
    s_temp = p_temp->next;
    p_temp->next = s_temp->next;
    free(s_temp);
    return head;
}