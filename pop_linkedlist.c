//Write a C program to implement the POP operation of a stack using single linked list. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *top; // Link the current top to the new node
    *top = newNode; // Update the top pointer
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return -1; // Return a value indicating the stack is empty
    }

    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next; // Update the top pointer
    free(temp); // Free the memory of the popped node
    return poppedValue;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL; // Initialize an empty stack
    int value, choice;

    // Menu for user input
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push operation
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2: // Pop operation
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3: // Display the stack
                display(top);
                break;
            case 4: // Exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4); // Repeat until user chooses to exit

    return 0;
}