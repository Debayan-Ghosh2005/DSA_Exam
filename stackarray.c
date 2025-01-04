//Write a menu driven C program to implement all operation of stack using array. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Declare an array to represent the stack and a variable for the top of the stack
int stack[MAX];
int top = -1;

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1) {
        return 1;  // Stack is full
    }
    return 0;
}

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1) {
        return 1;  // Stack is empty
    }
    return 0;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack is full! Cannot push %d onto the stack.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot pop an element.\n");
        return -1;
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No top element.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display all the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        // Display the menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Check if Stack is Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                // Pop operation
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                // Peek operation
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                // Display operation
                display();
                break;
            case 5:
                // Check if stack is empty
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                // Check if stack is full
                if (isFull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 7:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}