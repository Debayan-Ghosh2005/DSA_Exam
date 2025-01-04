// Write a C program to remove duplicates from a sorted single linked list. Start or End node will never be duplicated.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove duplicates from the sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        // If current node's data is equal to next node's data, skip the next node
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next; // Bypass the duplicate node
            free(temp); // Free the memory of the removed node
        } else {
            current = current->next; // Move to the next node
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to take user input and create a linked list
struct Node* inputList() {
    struct Node* head = NULL;
    int value, choice;

    do {
        printf("Enter the value: ");
        scanf("%d", &value);

        insertNode(&head, value);

        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return head;
}

int main() {
    struct Node* head = NULL;

    printf("Enter the elements for the linked list:\n");
    head = inputList();

    printf("Original Linked List: ");
    printList(head);

    // Remove duplicates from the sorted linked list
    removeDuplicates(head);

    printf("Linked List after removing duplicates: ");
    printList(head);

    return 0;
}