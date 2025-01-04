#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Function to enqueue an element (insert at the end of the queue)
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, both front and rear point to the new node
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        // Add the new node at the end and update the rear pointer
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to display the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL; // Initialize front of the queue
    struct Node* rear = NULL;  // Initialize rear of the queue
    int value;

    // Get user input to enqueue values
    while (1) {
        printf("Enter the value to enqueue into the queue (enter -1 to stop): ");
        scanf("%d", &value);

        if (value == -1) break;  // Stop input if the user enters -1
        
        // Enqueue the entered value into the queue
        enqueue(&front, &rear, value);
        
        // Display the current state of the queue
        display(front);
    }

    return 0;
}