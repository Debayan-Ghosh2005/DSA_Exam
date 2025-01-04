// Write a Menu Driven C Program to implement Circular QUEUE operations using Array  
//(i) Insert an element in the Circular QUEUE: CENQUE() 
//(ii) Delete an element from the Circular QUEUE: CDELQUE() 
//(iii) Display elements of the Circular QUEUE: CDISPLAY() 


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

// Define the Circular Queue structure
struct CircularQueue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Function to insert an element into the circular queue (enqueue)
void CENQUE(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot insert %d\n", value);
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // If the queue is empty, set front to 0
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->arr[queue->rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element from the circular queue (dequeue)
void CDELQUE(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot delete.\n");
    } else {
        int deletedValue = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;  // Queue becomes empty after deletion
        } else {
            queue->front = (queue->front + 1) % MAX;  // Move front to the next element
        }
        printf("%d deleted from the queue.\n", deletedValue);
    }
}

// Function to display the elements of the circular queue
void CDISPLAY(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No elements to display.\n");
    } else {
        int i = queue->front;
        printf("Queue elements: ");
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue->arr[queue->rear]);  // Print the last element
    }
}

// Main function to drive the program
int main() {
    struct CircularQueue queue;
    int choice, value;
    initQueue(&queue);

    while (1) {
        printf("\nMenu Driven Circular Queue Operations\n");
        printf("1. Insert an element (CENQUE)\n");
        printf("2. Delete an element (CDELQUE)\n");
        printf("3. Display the queue (CDISPLAY)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                CENQUE(&queue, value);
                break;
            case 2:
                CDELQUE(&queue);
                break;
            case 3:
                CDISPLAY(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}