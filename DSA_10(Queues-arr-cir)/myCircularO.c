#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "CircularQ"

#define maxsize 10 

#include <stdbool.h>
/*

This program is when bool is used , two methods of conditions are used .

bool Enqueue(int int_queue[], int *rear, int *count, int max_size, int data) {
    // 1. Guard against overflow
    if (*count == max_size) {
        return false; // Queue is full
    }

    // 2. Insert data at rear
    int_queue[*rear] = data;

    // 3. Increment rear circularly
    *rear = (*rear + 1) % max_size;

    // 4. Update element count
    (*count)++;

    return true; // Enqueue succeeded
}

bool Enqueue(int int_queue[], int front, int *rear, int max_size, int data) {
    // Check if the next step lands on front (queue is full)
    if ((*rear + 1) % max_size == front) {
        return false; // Queue is full (holds max_size - 1 items)
    }

    // Insert data at current rear
    int_queue[*rear] = data;

    // Advance rear circularly
    *rear = (*rear + 1) % max_size;

    return true;
}*/

void Enqueue (int *int_queue, int *rear, int max_size, int data)
{
	if (isFull (int_queue, max_size))
	{
		printf ("Queue is full\n");
		return;
	}

	int_queue[*rear] = data;
	*rear = (*rear + 1) % max_size;
}

int Dequeue(int int_queue[] , int * front , int max_size , int * data){
    if(isEmpty(int_queue , max_size)){
        printf("Queue is empty\n");
        return -1;
    }
    *data = int_queue[*front];
    int_queue[*front] = -INT_MAX;
    *front = (*front + 1)%max_size;
    return 0;
}

bool isFull(int *int_queue, int maxsize)
{
    for (int i = 0; i < maxsize; i++)
    {
        if (int_queue[i] == -INT_MAX)
            return false; // Found a free slot
    }
    return true; // All slots occupied
}

bool isEmpty(int * int_queue , int maxsize){
    for(int i = 0 ; i < maxsize ; i++){
        if(int_queue[i] != -INT_MAX){
            return false;
        }
    }
    return true;
}

int peek(int * int_queue , int max_size , int front , int *data){
    	if (isEmpty(int_queue, max_size))
	{
		printf ("Queue is emppty\n");
		return -1;
	}
    *data = int_queue[front];
    return 0;
}

void displayQ(int * int_queue , int front , int rear , int max_size){
    if (isEmpty(int_queue, max_size))
	{
		printf ("Queue is emppty\n");
		return -1;
	}
    while(front != rear){
        printf("%d" , int_queue[front]);
        front = (front + 1)%max_size;
    }
printf("%d" , int_queue[front]);
}

void printArray(int *int_queue, int max_size)
{
    for (int i = 0; i < max_size; i++)
    {
        if (int_queue[i] == -INT_MAX)
            printf("[-INT_MAX] ");
        else
            printf("[%d] ", int_queue[i]);
    }
    printf("\n");
}