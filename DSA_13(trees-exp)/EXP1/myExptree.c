#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExpTree.h"

static top = -1;
void inOrder(NODE *tree){
    if(tree == NULL){
        return;
    }
    inOrder(tree->left);
    printf("%c" , tree->data);
    inOrder(tree->right);
}

void preOrder(NODE *tree){
    if(tree == NULL){
        return;
    }
    printf("%c" , tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(NODE *tree){
    if(tree == NULL){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%c" , tree->data);
}

NODE *CreateNode(char c){
    NODE * Nnode = (NODE *)malloc(sizeof(NODE));
    if(!Nnode){
        printf("failed memory allocation");
        return NULL;
    }
    tree->right = NULL;
    tree->left = NULL;
    tree->data = c;
return Nnode;
}

int CheckChar(char c){
    if(c == '*' || c == '+' || c == '^' || c == '-' , c == '/'){
        return 1;
    }
    if (isalnum((unsigned char)ch)) {
        return 2;
    }
    return -1;
}

static int top = -1;
static NODE *stack[50]; // Internal helper stack for push() and pop()

void push(NODE *tree) {
    if (top >= 49) {
        printf("the stack is full\n");
        return;
    }
    stack[++top] = tree;
}

NODE *pop() {
    if (top == -1) {
        return NULL;
    }
    return stack[top--];
}

void construct_expression_tree(char *s , NODE *Stack[]){
    top = -1;
    int i = 0;
    while(s[i] != '\0'){
        if(CheckChar(s[i]) == 1){
            NODE *node = CreateNode(s[i]);
            NODE* a = pop();
            NODE* b = pop();
            node->left = b;
            node->right = a;
            push(node);
        }else if(CheckChar(s[i]) == 2){
            NODE *node = CreateNode(s[i]);
            push(node);
        }else{
            printf("invalid char is there");
            return;
        }
        i++;
    }
Stack[0] = pop();
}

#ifdef PREFIX
void construct_pfix_expression_tree(char *s, NODE *Stack[]) {
    top = -1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (CheckChar(s[i]) == 1) {
            NODE *node = CreateNode(s[i]);
            NODE *a = pop(); // Left child
            NODE *b = pop(); // Right child
            node->left = a;
            node->right = b;
            push(node);
        } else if (CheckChar(s[i]) == 2) {
            NODE *node = CreateNode(s[i]);
            push(node);
        } else {
            printf("invalid char is there\n");
            return;
        }
    }
    Stack[0] = pop();
}
#endif