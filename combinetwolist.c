// There are two linked list A and B containing the following data: 
//A: 7,5,3,1,20 
//B: 6,25,32,11,9 
//Write a function to combine the two lists such that the resulting list contains nodes in the following elements: 7,6,5,25,3,32,1,11,20,9


#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to append a node at the end of the linked list
void append(struct Node** head, int value) {
    struct Node* new_node = newNode(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to combine two linked lists alternately
struct Node* combineLists(struct Node* A, struct Node* B) {
    struct Node* combined = NULL;
    struct Node* temp = NULL;

    // Traverse both lists and combine alternately
    while (A != NULL && B != NULL) {
        // Add node from A
        append(&combined, A->data);
        A = A->next;

        // Add node from B
        append(&combined, B->data);
        B = B->next;
    }

    // If any elements are left in list A, add them to the combined list
    while (A != NULL) {
        append(&combined, A->data);
        A = A->next;
    }

    // If any elements are left in list B, add them to the combined list
    while (B != NULL) {
        append(&combined, B->data);
        B = B->next;
    }

    return combined;
}

int main() {
    struct Node* A = NULL;
    struct Node* B = NULL;

    // Create the first list A: 7, 5, 3, 1, 20
    append(&A, 7);
    append(&A, 5);
    append(&A, 3);
    append(&A, 1);
    append(&A, 20);

    // Create the second list B: 6, 25, 32, 11, 9
    append(&B, 6);
    append(&B, 25);
    append(&B, 32);
    append(&B, 11);
    append(&B, 9);

    // Combine the lists A and B
    struct Node* combined = combineLists(A, B);

    // Display the combined list
    printf("Combined List: ");
    display(combined);

    return 0;
}