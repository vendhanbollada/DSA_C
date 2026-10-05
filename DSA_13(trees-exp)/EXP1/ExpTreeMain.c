//			ExpTreeMain.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExpTree.h"

int main (int argc, char **argv) 
{
	char postfixExpr [100];
	NODE *eStack [50];
#ifdef PREFIX
   	printf ("Enter Prefix Expression : ");
#endif
#ifdef POSTFIX
	printf ("Enter Postfix Expression : ");
#endif
   	scanf ("%s", postfixExpr);
	// The following line is relevant when we have postfix exp as the input
#ifdef POSTFIX
   	construct_expression_tree(postfixExpr, eStack);
#endif
#ifdef PREFIX
	construct_pfix_expression_tree (postfixExpr, eStack);
#endif
   	printf ("\nIn-Order Traversal : ");
   	inOrder(eStack[0]);
   	printf ("\nPre-Order Traversal : ");
   	preOrder(eStack[0]);
   	printf ("\nPost-Order Traversal : ");
   	postOrder(eStack[0]);
   	return 0;
}