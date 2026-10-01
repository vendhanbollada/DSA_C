//					CheckPostFix.ch

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is a standard operator
bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch =='^');
}

// Function to validate the postfix expression
bool isValidPostfix(char postfix[]) 
{
    int len = strlen(postfix);
    
    // An empty expression is immediately invalid
    if (len == 0) 
	{
        return false;
    }

    // Counter to track the number of available operands
    int operandCounter = 0;

    // Scan the postfix expression from left to right
    for (int i = 0; i < len; i++) 
	{
        char ch = postfix[i];

        // Skip spaces if they are present in the string
        if (ch == ' ') 
		{
            continue;
        }

        if (isalnum(ch)) 
		{
            // If it is an operand (letter or digit), increment the counter
            operandCounter++;
        } 
        else if (isOperator(ch)) 
		{
            // An operator requires at least 2 operands to be available before it
            if (operandCounter < 2) {
                return false;
            }
            // The operator combines 2 operands into 1 result (net change: -1)
            operandCounter--;
        } 
        else 
		{
            // Any unsupported character makes the expression invalid
            return false;
        }
    }

    // A valid postfix expression must resolve down to exactly 1 final result
    return (operandCounter == 1);
}

int main(int argc, char **argv) 
{
	char expr [50];
	
	printf ("Key in a postfix expression:");
	scanf (" %s", expr);
	printf("Expression: %s -> %s\n", expr, isValidPostfix(expr) ? "VALID" : "INVALID");
    return 0;
}
