// Tree traversal in C
//					BTreeTraversal.h


typedef struct node 
{
  	int item;
  	struct node* left;
  	struct node* right;
} NODE;

// Inorder traversal
void inorderTraversal(NODE *);

// Preorder traversal
void preorderTraversal(NODE *);

// Postorder traversal
void postorderTraversal(NODE *);

// Create a new Node
NODE* create(int);

// Insert on the left of the node
NODE* insertLeft(NODE *, int);

// Insert on the right of the node
NODE* insertRight(NODE *, int);
