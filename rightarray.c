//Write a C program to right rotate an array.

#include <stdio.h>

// Function to right rotate the array by 'd' positions
void rightRotate(int arr[], int n, int d) {
    // Modulo operation to handle cases where d > n
    d = d % n;

    // Step 1: Reverse the entire array
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // Step 2: Reverse the first 'd' elements
    for (int i = 0; i < d / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[d - 1 - i];
        arr[d - 1 - i] = temp;
    }

    // Step 3: Reverse the remaining 'n-d' elements
    for (int i = d; i < (n + d) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - (i - d)];
        arr[n - 1 - (i - d)] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, d;

    // Input array size and elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number of positions to rotate the array
    printf("Enter the number of positions to right rotate: ");
    scanf("%d", &d);

    // Perform right rotation
    rightRotate(arr, n, d);

    // Print the rotated array
    printf("Array after right rotation: ");
    printArray(arr, n);

    return 0;
}