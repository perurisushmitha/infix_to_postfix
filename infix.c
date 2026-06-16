#include "headers.h"     // Includes required header files and function declarations

int top = -1;            // Stack top initialized to -1 indicating stack is empty

char stack[50];          // Array used to implement stack for operators

// Structure definition (currently not used in this program)
struct list
{
    char infix[50];      // Stores infix expression
    char postfix[50];    // Stores postfix expression

    struct list *next;   // Pointer to next node
};

// Function to push operator into stack
void push(char ch)
{
    stack[++top] = ch;   // Increment top and store operator
}

// Function to remove operator from stack
char pop()
{
    if(top != -1)        // Check whether stack is not empty
    {
        return(stack[top--]); // Return top element and decrement top
    }

    return '\0';         // Return NULL character if stack is empty
}

// Function to assign precedence to operators
int precedence(char p)
{
    if(p == '+' || p == '-')
    {
        return 1;        // Lower precedence
    }
    else if(p == '*' || p == '/')
    {
        return 2;        // Higher precedence
    }
}

int main()
{
    char s[100];         // Stores input infix expression

    printf("enter expression:\n");

    scanf("%s",s);       // Read infix expression from user

    char *p;             // Pointer used to traverse expression

    p = s;               // Point to first character of expression

    while(*p != '\0')    // Continue until end of string
    {
        // Check whether current character is an operand
        if((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
        {
            printf("%c",*p);  // Operands are directly printed in postfix
        }

        // Handle opening parenthesis
        else if(*p == '(')
        {
            push(*p);         // Push '(' into stack
        }

        // Handle closing parenthesis
        else if(*p == ')')
        {
            // Pop operators until matching '(' is found
            while(top != -1 && stack[top] != '(')
            {
                printf("%c",pop());
            }

            pop();            // Remove '(' from stack
        }

        // Handle operators
        else if(p == '' || *p == '/' || *p == '+' || *p == '-')
        {
            // Pop higher or equal precedence operators first
            while(top != -1 &&
                  precedence(stack[top]) >= precedence(*p))
            {
                printf("%c",pop());
            }

            // Push current operator into stack
            push(*p);
        }

        p++;                 // Move to next character
    }

    // Print remaining operators from stack
    while(top != -1)
    {
        printf("%c",pop());
    }
}
