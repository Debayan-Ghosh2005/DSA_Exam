// Write a C program to implement the PUSH operation of a stack using single linked list.

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
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int value, choice;

    while (1) {
        printf("Enter the value to push onto the stack: ");
        scanf("%d", &value);
        
        // Perform PUSH operation
        push(&top, value);
        
        // Display the stack
        display(top);
        
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0) break;
    }

    return 0;
}