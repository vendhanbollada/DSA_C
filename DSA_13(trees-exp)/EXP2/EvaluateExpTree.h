//					EvaluateExpTree.h

typedef struct node
{
	int value;
	struct node *left, *right;
} NODE;


int solveExpressionTree(NODE *);

//function to create a node
NODE* new_node(int); 