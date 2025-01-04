//) Write a C program to compare two linked lists are identical or not.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
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

// Function to compare two linked lists
int compareLists(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0;  // Lists are not identical
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // If both lists have reached the end at the same time, they are identical
    if (head1 == NULL && head2 == NULL) {
        return 1;  // Lists are identical
    }

    return 0;  // One list is longer than the other
}

// Function to take user input and create a linked list
struct Node* inputList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int value, choice;

    do {
        printf("Enter the value: ");
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
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

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Enter the elements for the first linked list:\n");
    list1 = inputList();

    printf("Enter the elements for the second linked list:\n");
    list2 = inputList();

    printf("\nFirst Linked List: ");
    displayList(list1);

    printf("Second Linked List: ");
    displayList(list2);

    // Compare the two lists
    if (compareLists(list1, list2)) {
        printf("\nThe two linked lists are identical.\n");
    } else {
        printf("\nThe two linked lists are not identical.\n");
    }

    return 0;
}