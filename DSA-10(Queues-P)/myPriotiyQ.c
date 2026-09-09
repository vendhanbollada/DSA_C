#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include "priorityq.h"


NODE * newNode(int priotiy , int data){
    NODE * newNode = (NODE*)malloc(sizeof(NODE));
    if(!newNode){
        printf("memory allocation failed");
        return NULL;
    }
    newNode->data = data;
    newNode->priority = priotiy;
    newNode->next = NULL;
return newNode;
}

void InsertNode(NODE ** head , int * data , int *priority){
    nNode = newNode(int *priority , int *data);
    for(NODE * ptemp = *head ;  (*head)->priority >= nNode->priority ; ptemp = ptemp->next){

    
}

void DeleteNode(NODE ** head , int *data)