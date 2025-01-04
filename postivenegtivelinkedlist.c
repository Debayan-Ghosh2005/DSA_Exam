//  A linked list contains some positive numbers and some negative numbers. Using this linked list write a program in C to create two more linked lists, one containing all positive numbers and another containing all negative numbers. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create two separate linked lists for positive and negative numbers
void separatePositiveNegative(struct Node* original, struct Node** positive, struct Node** negative) {
    while (original != NULL) {
        if (original->data >= 0) {
            insertNode(positive, original->data);  // Add to positive list
        } else {
            insertNode(negative, original->data);  // Add to negative list
        }
        original = original->next;
    }
}

int main() {
    struct Node* head = NULL;       // Original linked list
    struct Node* positiveList = NULL; // List for positive numbers
    struct Node* negativeList = NULL; // List for negative numbers

    int n, value;

    // Take user input for the linked list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    // Separate positive and negative numbers
    separatePositiveNegative(head, &positiveList, &negativeList);

    // Display the original, positive, and negative lists
    printf("Original Linked List: ");
    displayList(head);

    printf("Positive Numbers Linked List: ");
    displayList(positiveList);

    printf("Negative Numbers Linked List: ");
    displayList(negativeList);

    return 0;
}