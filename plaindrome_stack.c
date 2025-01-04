#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure of a stack node
struct Stack {
    char data;
    struct Stack* next;
};

// Function to push an element onto the stack
void push(struct Stack** top, char value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    
    // Check for memory allocation failure
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *top; // Link the current top to the new node
    *top = newNode; // Update the top pointer
}

// Function to pop an element from the stack
char pop(struct Stack** top) {
    if (*top == NULL) {
        return '\0'; // Return a null character if the stack is empty
    }

    struct Stack* temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->next; // Update the top pointer
    free(temp); // Free the memory of the popped node
    return poppedValue;
}

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    struct Stack* stack = NULL; // Initialize an empty stack
    int length = strlen(str);
    
    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) { // Consider only alphanumeric characters
            push(&stack, tolower(str[i])); // Convert to lowercase and push
        }
    }

    // Compare each character in the string with the popped character from the stack
    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            char stackTop = pop(&stack); // Get a character from the stack
            if (tolower(str[i]) != stackTop) {
                return 0; // Not a palindrome if characters do not match
            }
        }
    }
    return 1; // The string is a palindrome if all characters match
}

int main() {
    char str[100];
    
    // Get user input for the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';
    
    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}