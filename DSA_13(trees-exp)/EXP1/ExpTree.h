//			ExpTree.h		

typedef struct node 
{
   	char data;
   	struct node *left;
	struct node *right;
} NODE;

NODE *CreateNode (char );

#ifdef POSTFIX
void construct_expression_tree(char *, NODE *[]);
#endif
#ifdef PREFIX
void construct_pfix_expression_tree(char *, NODE *[]);
#endif
void inOrder (NODE *);
void preOrder (NODE *);
void postOrder (NODE *);
int CheckChar (char); // returns 1 if it is an operator; 2 if it is an operand
		      // and -1 if it is neither
// Support the following operators
// +, -, *, / and ^ (exponentiation)
void push (NODE *);
NODE *pop ();
