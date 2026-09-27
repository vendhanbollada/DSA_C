// Tree traversal in C
//					BTreeTraversal.c

#include <stdio.h>
#include <stdlib.h>
#include "BTreeTraversal.h"

// Inorder traversal
void inorderTraversal(NODE* root) 
{
  	if (root == NULL) 
		return;
  	inorderTraversal(root->left);
  	printf("%d ", root->item);
  	inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(NODE* root) 
{
  	if (root == NULL) 
		return;
  	printf("%d ", root->item);
  	preorderTraversal(root->left);
  	preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(NODE* root) 
{
  	if (root == NULL) 
		return;
  	postorderTraversal(root->left);
  	postorderTraversal(root->right);
  	printf("%d ", root->item);
}

// Create a new Node
NODE* create(int value) 
{
  	NODE* newNode = malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf ("Memory allocation failure\n");
		exit (0);
	}
  	newNode->item = value;
  	newNode->left = NULL;
  	newNode->right = NULL;

  	return newNode;
}

// Insert on the left of the node
NODE* insertLeft(NODE* root, int value) 
{
  	root->left = create(value);
  	return root->left;
}

// Insert on the right of the node
NODE* insertRight(NODE* root, int value) 
{
  	root->right = create(value);
  	return root->right;
}

