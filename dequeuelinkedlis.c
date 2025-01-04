//  Write a C program to implement the DEQUEUE of a queue operation using single linked list.   

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Function to enqueue an element into the queue
void enqueue(struct Node** front, struct Node** rear, int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize the new node
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    // Otherwise, add the new node to the end of the queue and update rear
    (*rear)->next = newNode;
    *rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 if the queue is empty
    }

    // Store the data from the front node
    struct Node* temp = *front;
    int data = temp->data;

    // Move the front pointer to the next node
    *front = (*front)->next;

    // If the front is NULL, set rear to NULL as well
    if (*front == NULL) {
        *rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);

    // Return the dequeued value
    return data;
}

// Function to display the queue
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;  // Initialize the front pointer of the queue
    struct Node* rear = NULL;   // Initialize the rear pointer of the queue

    int choice, value;

    // Menu for operations
    while (1) {
        printf("\nQueue Operations using Linked List:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                // Dequeue operation
                value = dequeue(&front, &rear);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                // Display the queue
                displayQueue(front);
                break;
            case 4:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}