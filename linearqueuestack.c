// Write a C Program to implement Linear Queue using two Stacks

#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of the queue

// Define the structure of a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;  // Return an error code if stack is empty
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Function to enqueue an element (add to the queue)
void enqueue(struct Stack* stack1, int value) {
    push(stack1, value);
}

// Function to dequeue an element (remove from the queue)
int dequeue(struct Stack* stack1, struct Stack* stack2) {
    if (isEmpty(stack1) && isEmpty(stack2)) {
        printf("Queue is empty!\n");
        return -1;  // Return an error code if both stacks are empty
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            int value = pop(stack1);
            push(stack2, value);
        }
    }

    // Pop the element from stack2 (which represents the front of the queue)
    return pop(stack2);
}

// Function to display the elements in the queue (from front to rear)
void displayQueue(struct Stack* stack1, struct Stack* stack2) {
    if (isEmpty(stack1) && isEmpty(stack2)) {
        printf("Queue is empty!\n");
        return;
    }

    // Display elements from stack2
    if (!isEmpty(stack2)) {
        for (int i = stack2->top; i >= 0; i--) {
            printf("%d ", stack2->arr[i]);
        }
    }

    // Display elements from stack1 (in reverse order)
    if (!isEmpty(stack1)) {
        for (int i = 0; i <= stack1->top; i++) {
            printf("%d ", stack1->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    struct Stack stack1, stack2;
    int choice, value;

    // Initialize both stacks
    initStack(&stack1);
    initStack(&stack2);

    while (1) {
        printf("\nQueue Operations using Two Stacks\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&stack1, value);
                break;
            case 2:
                value = dequeue(&stack1, &stack2);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                printf("Queue: ");
                displayQueue(&stack1, &stack2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}