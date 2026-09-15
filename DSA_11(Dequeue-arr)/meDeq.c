#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "DeqArray.h"


void addFront(int *arr, int item, int *pfront, int *prear, int maxsize)
{
    if (*pfront == -1) // Case 1: Empty queue
    {
        *pfront = 0;
        *prear = 0;
        arr[0] = item;
    }
    else if (*pfront > 0) // Case 2: Space exists to the left
    {
        (*pfront)--;
        arr[*pfront] = item;
    }
    else // Case 3: *pfront == 0 (must shift elements right)
    {
        if (*prear == maxsize - 1)
        {
            printf("Queue is full\n");
            return;
        }

        for (int i = *prear; i >= *pfront; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[*pfront] = item;
        (*prear)++;
    }
}

void addRear(int *arr, int item, int *pfront, int *prear, int maxsize)
{
    if (*prear == maxsize - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (*pfront == -1)
    {
        *pfront = 0;
        *prear = 0;
    }
    else
    {
        (*prear)++;
    }

    arr[*prear] = item;
}

int delFront(int *arr, int *pfront, int *prear)
{
    if (*pfront == -1)
    {
        printf("Queue is empty\n");
        return -INT_MAX;
    }

    int data = arr[*pfront];
    arr[*pfront] = -INT_MAX;

    // If it was the only remaining element, reset to empty state
    if (*pfront == *prear)
    {
        *pfront = -1;
        *prear = -1;
    }
    else
    {
        (*pfront)++;
    }

    return data;
}

int delRear(int *arr , int *pfront , int *prear ){
    if(*prear == -1){
        printf("the list is empty");
        return -1;
    }
    int data = int[*prear];
    int[*prear] = -INT_MAX;
    if(*prear == *pfront){
        *pfront = -1;
        *prear = -1;
    }else{
        (*prear)--
    }
return data;
}

void display(int *arr , int maxsize){
    for(int i = 0 ; i < maxsize ; i++){
        if(arr[i] != -INT_MAX){
            printf("%d->" , arr[i]);
        }
    }
    printf("over\n")
}

int count(int *arr , int maxsize){
    int count = 0 ;
    for(int i = 0 ; i < maxsize ; i++){
        if(arr[i] != -INT_MAX){
            count++;
        }
    }
return count;
}

int frontEle(int *arr, int front)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -INT_MAX;
    }
    return arr[front];
}

int rearEle(int *arr, int rear)
{
    if (rear == -1)
    {
        printf("Queue is empty\n");
        return -INT_MAX;
    }
    return arr[rear];
}