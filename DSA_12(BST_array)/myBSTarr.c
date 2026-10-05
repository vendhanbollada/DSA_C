#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include "BST_Arrays.h"

int get_right_child(char *tree, int index, int max_nodes)
{
    // Parent must be within bounds and actually exist
    if (index < 0 || index >= max_nodes || tree[index] == -CHAR_MAX)
    {
        return -1;
    }

    int right_index = 2 * index + 2;

    // Check if right child index is within bounds and populated
    if (right_index < max_nodes && tree[right_index] != -CHAR_MAX)
    {
        return right_index;
    }

    return -1;
}

int get_left_child(char *tree ; int index , int max_nodes){
    
    if(index < 0 || index >= max_nodes || tree[index] == -CHAR_MAX ){
        return -1;
    }
    int left_index = 2*index + 1;
    
    if(tree[left_index] != -CHAR_MAX || left_index < max_nodes){
        return left_index;
    }
return -1;
}

void preorder(char* tree , int index , int max_nodes){

    if (index < 0 || index >= max_nodes || tree[index] == -CHAR_MAX)
    {
        return;
    }
    printf("%c ", tree[index]);
    preorder(tree, 2 * index + 1, max_nodes);
    preorder(tree, 2 * index + 2, max_nodes);
}

void inorder(char * tree , int index , int max_nodes){
    if (index < 0 || index >= max_nodes || tree[index] == -CHAR_MAX)
    {
        return;
    }
    // 2. L: Traverse left child
    inorder(tree, 2 * index + 1, max_nodes);
    // 3. V: Visit current node
    printf("%c ", tree[index]);
    // 4. R: Traverse right child
    inorder(tree, 2 * index + 2, max_nodes);
}

void postorder( char * tree , int index , int max_nodes){
    if(index < 0 || index >= max_nodes || tree[index] == -CHAR_MAX){
        return;
    }
    postorder(tree , 2*index + 1 , max_nodes);
    postorder(tree , 2*index + 2 , max_nodes);
    printf("%c" , tree[index]);
}

void insert(char *tree , int max_nodes , char val){
    int curr = 0; // Always start at the root

    while (curr < max_nodes)
    {
        // 1. Found an empty slot: insert and terminate
        if (tree[curr] == -CHAR_MAX)
        {
            tree[curr] = value;
            return;
        }

        // 2. Reject duplicate values
        if (value == tree[curr])
        {
            printf("Value %c already exists in tree\n", value);
            return;
        }

        // 3. Navigate down the tree using 0-based BST child formulas
        if (value < tree[curr])
        {
            curr = 2 * curr + 1; // Move to left child
        }
        else
        {
            curr = 2 * curr + 2; // Move to right child
        }
    }

    // If the loop exits, curr >= max_nodes
    printf("Error: Tree array overflow. Cannot insert %c\n", value);
}

void dumpArray(char * tree , int max_nodes){
    printf("Array Dump:\n");
    for (int i = 0; i < max_nodes; i++)
    {
        if (tree[i] == -CHAR_MAX)
        {
            printf("[%d: -] ", i);
        }
        else
        {
            printf("[%d: %c] ", i, tree[i]);
        }
    }
    printf("\n");
}
