#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "CircularQ"

#define maxsize

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

void Enqueue(int * int_queue , int * rear , int max_size , int data){
        if (*count == max_size) {
        return false; // Queue is full
        }

    int_queue[*rear] = data;

    *rear = (*rear + 1) % max_size;

    (*count)++;
}

isFull(int * rear , int * maxsize){
    return rear 
}