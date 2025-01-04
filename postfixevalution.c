//Write a C Program for Evaluating the Postfix Expression: 3 8 + 9 8 / - 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For checking if the character is a digit

// Stack Node structure
struct Stack {
    int data;
    struct Stack* next;
};

// Function to push an element onto the stack
void push(struct Stack** top, int value) {
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
int pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;  // Return -1 to indicate error
    }

    struct Stack* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Move top to the next node
    free(temp);            // Free the memory of the popped node
    return poppedValue;    // Return the popped value
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* expression) {
    struct Stack* stack = NULL;  // Initialize the stack
    int i = 0;

    while (expression[i] != '\0') {
        char current = expression[i];

        // If the character is a number, push it onto the stack
        if (isdigit(current)) {
            int num = current - '0';  // Convert char to int
            push(&stack, num);
        }
        // If the character is an operator
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            // Pop the two top operands from the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            int result;
            // Perform the operation based on the operator
            if (current == '+') {
                result = operand1 + operand2;
            } else if (current == '-') {
                result = operand1 - operand2;
            } else if (current == '*') {
                result = operand1 * operand2;
            } else if (current == '/') {
                result = operand1 / operand2;
            }

            // Push the result back onto the stack
            push(&stack, result);
        }

        i++;
    }

    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char postfixExpression[100];

    // Get user input for the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%[^\n]%*c", postfixExpression);  // Read the entire line

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);

    // Print the result
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}