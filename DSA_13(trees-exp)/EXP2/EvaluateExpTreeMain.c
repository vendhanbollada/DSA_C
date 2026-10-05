//			EvaluateExpTreeMain.c

#include <stdio.h>
#include <stdlib.h>
#include "EvaluateExpTree.h"

int main ()
{
    int result;
   	NODE *root = new_node ('/'); 
   
   	root->left = new_node('+');
   	root->left->left = new_node(18);
   	root->left->right = new_node(10);
   	root->right = new_node ('*');
   	root->right->left = new_node(2);
   	root->right->right = new_node(7);
   	result = solveExpressionTree(root);
    printf ("The result is %d\n", result);
   	return 0;
}