#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"StackOps_2.h"

STACK *initStack(void){
    STACK *myStack = (STACK*)malloc(sizeof(STACK));
    myStack->top = -1;
}

bool isEmpty(STACK *myStack){
    if(myStack->top == -1)
        return true;
    else
        return false; 
    
}
bool isFull(STACK *mystack){
    if(myStack->top == STACK_SIZE - 1)
        return true;
    else 
        return false;
}

void push(STACK* mystack , int data){
    if(isFull(mystack)){
        printf("The Stack is full");
    }else{
    mystack->top++;
    mystack->members[mystack->top] = data;
    }
}

int pop(STACK *mystack)
{
    if (isEmpty(mystack))
        return -1;

    return mystack->members[mystack->top--];
}

int peek(STACK * mystack){
    if(isEmpty(mystack))
        printf("the stack is empty");
    return -1 ;
    else{
        return myStack->members[myStack->top];
    }
}

void printStack(STACK *myStack){
int i = 0;
    while(i <= myStack->top){
        printf("%d" , myStack->members[i]);
        i++;
    }
}