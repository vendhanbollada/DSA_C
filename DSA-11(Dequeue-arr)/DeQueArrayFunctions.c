// Deque implementation in C using Arrays (Non-circular)

//			DequeArrayFunctions.c

#include <stdio.h>
#include <limits.h>
#include "DeqArray.h"

void addFront (int *arr, int item, int *pfront, int *prear, int maxsize) 
{
  	int i, k, c;

  	if (*pfront == 0 && *prear == maxsize - 1) 
	{
    	printf("\nDeque is full.\n");
    	return;
  	}

  	if (*pfront == -1) 
	{
    	*pfront = *prear = 0;
    	arr[*pfront] = item;
    	return;
  	}

  	if (*prear != maxsize - 1) 
	{
    	c = count(arr, maxsize);
    	k = *prear + 1;
    	for (i = 1; i <= c; i++) 
		{
      		arr[k] = arr[k - 1];
      		k--;
    	}
    	arr[k] = item;
    	*pfront = k;
    	(*prear)++;
  	} 
	else 
	{
    	(*pfront)--;
    	arr[*pfront] = item;
  	}
}

void addRear (int *arr, int item, int *pfront, int *prear, int maxsize) 
{
  	int i, k;

  	if (*pfront == 0 && *prear == maxsize - 1) 
	{
    	printf("\nDeque is full.\n");
    	return;
  	}

  	if (*pfront == -1) 
	{
    	*prear = *pfront = 0;
    	arr[*prear] = item;
    	return;
  	}

  	if (*prear == maxsize - 1) 
	{
    	k = *pfront - 1;
    	for (i = *pfront - 1; i < *prear; i++) 
		{
      		k = i;
      		if (k == maxsize - 1)
        		arr[k] = 0;
      		else
        		arr[k] = arr[i + 1];
    	}
    	(*prear)--;
    	(*pfront)--;
  	}
  	(*prear)++;
  	arr[*prear] = item;
}

int delFront(int *arr, int *pfront, int *prear) 
{
  	int item;

  	if (*pfront == -1) 
	{
    	printf("\nDeque is empty.\n");
    	return 0;
  	}

  	item = arr[*pfront];
  	arr[*pfront] = -INT_MAX;

  	if (*pfront == *prear)
    	*pfront = *prear = -1;
  	else
    	(*pfront)++;

  	return item;
}

int delRear (int *arr, int *pfront, int *prear) 
{
  	int item;

  	if (*pfront == -1) 
	{
    	printf("\nDeque is empty.\n");
    	return 0;
  	}

  	item = arr[*prear];
  	arr[*prear] = -INT_MAX;
  	(*prear)--;
  	if (*prear == -1)
    	*pfront = -1;
  	return item;
}

void display(int *arr, int maxsize) 
{
  	int i;

  	printf("\n front:  ");
  	for (i = 0; i < maxsize; i++)
    	printf("  %d", arr[i]);
  	printf("  :rear");
	printf ("\n");
}

int count(int *arr, int maxsize) 
{
  	int numEle = 0, i;

  	for (i = 0; i < maxsize; i++) 
	{
    	if (arr[i] != -INT_MAX)
      		numEle ++;
  	}
  	return numEle;
}

int frontEle (int *arr, int front)
{
	int retVal = -INT_MAX;

	if (front != -1)
		retVal = arr [front];

	return retVal;
}

int rearEle (int *arr, int rear)
{
	int retVal = -INT_MAX;

	if (rear != -1)
		retVal = arr [rear];

	return retVal;
}
