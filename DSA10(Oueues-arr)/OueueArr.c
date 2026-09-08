#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueArray.h"

#define MAX_SIZE 10

void Enqueue(int * int_queue , int *rear , int MAX_SIZE , int data){
    if((*rear) <= MAX_SIZE - 1){
        int_queue[*rear] = data;
        *p_rear = rear + 1;
    }else{
        printf("the list is full");
    }
}

void Dequeue(int * int_queue , int *)\


int Peek(int int_queue[] , int front , int rear , int *data){
    int retVal = 0 ;
    if(front >= rear){
        
    }else{

    }
}

bool isFull(int fornt , int rear){
    return (fornt == rear);
}

bool isEmpty(int fornt , int rear){
    return(fornt >= rear)
}

// do everything and check this functions
