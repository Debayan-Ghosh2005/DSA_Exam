// There are two linked lists L1 and L2 containing the following data: 
//L1: 3, 7,10,15,16,9,22,17,32 
//L2: 16,2,9,13,47,8,10,1,28 
//Write a C program to create a linked list L3 that contains only those elements that are  common in linked list L1 and L2.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
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

// Function to print the list
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

// Function to check if an element is in the list
int isInList(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;  // Element found
        }
        temp = temp->next;
    }
    return 0;  // Element not found
}

// Function to create a list of common elements from two lists
struct Node* createCommonList(struct Node* head1, struct Node* head2) {
    struct Node* commonList = NULL;
    struct Node* temp = head1;

    while (temp != NULL) {
        if (isInList(head2, temp->data)) {
            insertNode(&commonList, temp->data);
        }
        temp = temp->next;
    }

    return commonList;
}

int main() {
    struct Node *L1 = NULL, *L2 = NULL, *L3 = NULL;

    // Create linked list L1
    insertNode(&L1, 3);
    insertNode(&L1, 7);
    insertNode(&L1, 10);
    insertNode(&L1, 15);
    insertNode(&L1, 16);
    insertNode(&L1, 9);
    insertNode(&L1, 22);
    insertNode(&L1, 17);
    insertNode(&L1, 32);

    // Create linked list L2
    insertNode(&L2, 16);
    insertNode(&L2, 2);
    insertNode(&L2, 9);
    insertNode(&L2, 13);
    insertNode(&L2, 47);
    insertNode(&L2, 8);
    insertNode(&L2, 10);
    insertNode(&L2, 1);
    insertNode(&L2, 28);

    // Print the input lists
    printf("Linked List L1: ");
    printList(L1);

    printf("Linked List L2: ");
    printList(L2);

    // Create L3 with common elements from L1 and L2
    L3 = createCommonList(L1, L2);

    // Print the common elements in L3
    printf("Linked List L3 (Common Elements): ");
    printList(L3);

    return 0;
}
