// Tree traversal in C
//						BTreeMain.c

#include <stdio.h>
#include <stdlib.h>
#include "BTreeTraversal.h"

int main(int argc, char **argv) 
{
	int height , choice;
	NODE *root = NULL , *ptemp;
	printf("Welcome to the progarm , enter the height the program");
	scanf("%d" , &height);
  	NODE* root = create(height);
	printf("1)\n2)\n3)\n4)\n")
	swtich(choice){
		case "IL":
			
		case "IR":

		case "":
			swtich(choice){
				int sec_choice;
				printf("how you want to transerval\n1)post-order 2)pre-order 3)in-order");
				scanf("%d" , sec_choice);
				case "1"
			}
	}

}
/*
	  	NODE* root = create(1);
  	insertLeft(root, 4);
  	insertRight(root, 6);
  	insertLeft(root->left, 42);
  	insertRight(root->left, 3);
  	insertLeft(root->right, 2);
  	insertRight(root->right, 33);


  	printf("Traversal of the inserted binary tree \n");
  	printf("Inorder traversal \n");
  	inorderTraversal(root);

  	printf("\nPreorder traversal \n");
  	preorderTraversal(root);

  	printf("\nPostorder traversal \n");
  	postorderTraversal(root);
*/