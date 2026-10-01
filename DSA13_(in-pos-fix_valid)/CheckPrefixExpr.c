//					CheckPrefixExpr.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is an operator
bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to validate the prefix expression
bool isValidPrefix(char prefix[]) 
{
    int len = strlen(prefix);
    
    // An empty expression is invalid
    if (len == 0) 
	{
        return false;
    }

    // Counter to track the net requirement of operands
    int operandCounter = 0;

    // Scan the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) 
	{
        char ch = prefix[i];

        // Skip spaces if any are present
        if (ch == ' ') 
		{
            continue;
        }

        if (isalnum(ch)) 
		{
            // If it is an operand (alphanumeric), increment the counter
            operandCounter++;
        } 
        else if (isOperator(ch)) 
		{
		
            // An operator requires at least 2 operands ahead of it in reverse scan
            if (operandCounter < 2) {
                return false;
            }
            // An operator combines 2 operands into 1 result (net change: -1 operand)
            operandCounter--;
        } 
        else 
		{
            // Invalid character found
            return false;
        }
    }

    // A valid prefix expression will reduce to exactly 1 final result
    return (operandCounter == 1);
}

int main(int argc, char **argv) 
{
	char expr [50];
	
	printf ("Key in a prefix expression:");
	scanf (" %s", expr);
    printf("Expression: %s -> %s\n", expr, isValidPrefix(expr) ? "VALID" : "INVALID");
	return 0;
}
