#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include<EvaluateExpTree.h">


NODE* new_node(int val){
    NODE * node = (NODE *)malloc(sizeof(NODE));
    if(!node) return NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = val;
return node;
}

int solveExpressionTree(NODE *root) {
    // 1. Guard against empty node
    if (root == NULL) {
        return 0;
    }

    // 2. Base case: Leaf node (contains an operand/number)
    if (root->left == NULL && root->right == NULL) {
        return root->value;
    }

    // 3. Recursive step: Solve sub-expressions
    int left_val = solveExpressionTree(root->left);
    int right_val = solveExpressionTree(root->right);

    // 4. Apply operator
    switch (root->value) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            if (right_val == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            return left_val / right_val;
        default:
            return 0;
    }
}



