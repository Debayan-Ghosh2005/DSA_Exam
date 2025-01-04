// Write a C program to check a single link list is palindrome or not. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the last node and add the new node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the list
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

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL) {
        return 1; // Empty list is considered a palindrome
    }

    // Step 1: Find the middle of the linked list
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct Node* secondHalf = reverseList(slow);

    // Step 3: Compare the first half and second half of the list
    struct Node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1; // Palindrome
}

int main() {
    struct Node* head = NULL;  // Initialize the linked list
    int n, value;

    // Take input for the number of elements in the list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    // Take input for the elements of the list
    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);  // Insert elements into the list
    }

    // Display the original list
    printf("Original list: ");
    displayList(head);

    // Check if the list is palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}