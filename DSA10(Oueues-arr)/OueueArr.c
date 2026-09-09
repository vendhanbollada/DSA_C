#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueArray.h"

#define MAX_SIZE 10

void Enqueue(int * int_queue , int *rear , int MAX_SIZE , int data){
    if((*rear) < MAX_SIZE){
        int_queue[*rear] = data;
        *rear = *rear + 1;
    }else{
        printf("the list is full");
    }
}

int Dequeue(int *int_queue, int *front, int *rear, int *data)
{
    // 1. Guard check: Is the queue empty?
    if (*front >= *rear)
    {
        printf("Queue is empty\n");
        return -1;
    }

    // 2. Extract the item at the front index
    *data = int_queue[*front];

    // 3. Advance the front index
    *front = *front + 1;

    // 4. Return success code
    return 0;
}


int Peek(int int_queue[] , int front , int rear , int *data){
    if(front >= rear){
        printf("Queue is empty");
        return -1;
    }
    *data = int_queue[front];
    return 0;
}

bool isFull(int rear , int MAX_SIZE){
    return (rear >= MAX_SIZE);
}

bool isEmpty(int front , int rear , int MAX_SIZE){
    (void)MAX_SIZE;
    return front >= rear ;
}

void ShowNodes(int int_queue[], int front, int rear)
{
    if (front >= rear)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i < rear; i++)
    {
        printf("%d ", int_queue[i]);
    }
    printf("\n");
}
// do everything and check this functions
