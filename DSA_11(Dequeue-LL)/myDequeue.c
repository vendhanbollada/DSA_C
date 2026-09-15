#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "DequeList.h"


NODE * newNode (){
    if(NODE * newNode = (NODE*)malloc(sizeof(NODE)) == NULL){
        printf("memory allocation failed");
        return;
    }
    printf("enter the value");
    if(scanf("%d" , &newNode) == -1){
        printf("invalid input");
        return;
    }
newNode->next == NULL;
}

int Dequeue(NODE ** front , NODE **rear ){
    
}

int DeleteLast(NODE ** head , NODE * tail){

}

void InsertFirst(int item , NODE ** head , NODE **tail){

}

void PrintList(NODE ** head){
    if(*head == NULL){
        printf("the list is empty");
        return;
    }
    for(NODE * ptemp = *head ; ptemp != NULL ; ptemp = ptemp->next){
        printf("%d" , ptemp->info);
    }
printf("End");
}