//Write a C program to transform the following infix expression to postfix expression: (A+B^D)*(D/E) 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For checking if a character is a letter or not

// Stack Node structure
struct Stack {
    char data;
    struct Stack* next;
};

// Function to push an element onto the stack
void push(struct Stack** top, char value) {
    // Allocate memory for a new node
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;  // Set data
    newNode->next = *top;    // Link to the current top
    *top = newNode;          // Move top to the new node
}

// Function to pop an element from the stack
char pop(struct Stack** top) {
    if (*top == NULL) {
        return '\0';  // Return null if stack is empty
    }

    struct Stack* temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->next;  // Move top to the next node
    free(temp);            // Free the memory of the popped node
    return poppedValue;    // Return the popped value
}

// Function to return the precedence of operators
int precedence(char operator) {
    if (operator == '^') return 3;  // Highest precedence
    if (operator == '*' || operator == '/') return 2;  // Medium precedence
    if (operator == '+' || operator == '-') return 1;  // Lowest precedence
    return 0;  // Parenthesis or other characters
}

// Function to convert an infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = NULL;  // Stack is initially empty
    int k = 0;  // Index for the postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If the character is an operand (A-Z or a-z), add it directly to the output
        if (isalpha(current)) {
            postfix[k++] = current;
        }
        // If the character is '(', push it onto the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If the character is ')', pop from stack until '(' is found
        else if (current == ')') {
            while (stack != NULL && stack->data != '(') {
                postfix[k++] = pop(&stack);  // Pop from stack and add to postfix
            }
            pop(&stack);  // Discard '(' from the stack
        }
        // If the character is an operator (+, -, *, /, ^)
        else {
            while (stack != NULL && precedence(stack->data) >= precedence(current)) {
                postfix[k++] = pop(&stack);  // Pop operators from stack with higher or equal precedence
            }
            push(&stack, current);  // Push the current operator onto the stack
        }
    }

    // Pop remaining operators from the stack
    while (stack != NULL) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];

    // Get user input for the infix expression
    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);  // Read the entire line (including spaces)

    // Convert the infix expression to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}