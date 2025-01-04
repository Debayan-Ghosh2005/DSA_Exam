//  Write a C Program to Construct a Binary Search tree and traverse the tree in a) Preorder, b) Inorder, c) Postorder. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given value
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Insert in the right subtree
    }

    // Return the (unchanged) node pointer
    return root;
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Print root
        preorder(root->left);       // Traverse the left subtree
        preorder(root->right);      // Traverse the right subtree
    }
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Traverse the left subtree
        printf("%d ", root->data); // Print root
        inorder(root->right);      // Traverse the right subtree
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse the left subtree
        postorder(root->right);    // Traverse the right subtree
        printf("%d ", root->data); // Print root
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    // Take the number of nodes as input
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    // Input elements and construct the binary search tree
    printf("Enter %d elements to insert into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display tree traversals
    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}