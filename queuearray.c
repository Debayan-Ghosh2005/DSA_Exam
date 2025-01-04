// Write a menu driven C program to implement all operation of queue using array.  

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Declare an array to represent the queue and two variables for front and rear
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    if (rear == MAX - 1) {
        return 1;  // Queue is full
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;  // Queue is empty
    }
    return 0;
}

// Function to enqueue an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {  // If the queue is empty, set front to 0
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        front++;
        return dequeuedValue;
    }
}

// Function to peek the front element of the queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty! No front element.\n");
        return -1;
    } else {
        return queue[front];
    }
}

// Function to display all the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        // Display the menu
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Check if Queue is Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                // Dequeue operation
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                // Peek operation
                value = peek();
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;
            case 4:
                // Display operation
                display();
                break;
            case 5:
                // Check if queue is empty
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                // Check if queue is full
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
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