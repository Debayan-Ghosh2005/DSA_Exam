// Write a program in C to delete duplicate elements from an array of 20 integers. 

#include <stdio.h>

#define SIZE 20

// Function to remove duplicates from the array
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;  // If the array has 0 or 1 element, return the same length
    }

    int i, j = 0;

    // Loop to check each element in the array
    for (i = 1; i < n; i++) {
        int isDuplicate = 0;

        // Check if the current element is already in the result part of the array
        for (int k = 0; k <= j; k++) {
            if (arr[i] == arr[k]) {
                isDuplicate = 1;  // Element is a duplicate
                break;
            }
        }

        // If the element is not a duplicate, add it to the result
        if (!isDuplicate) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;  // Return the length of the array after removing duplicates
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    int n;

    // Take user input for the number of elements in the array
    printf("Enter the number of elements (up to %d): ", SIZE);
    scanf("%d", &n);

    // Take input for the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original array:\n");
    displayArray(arr, n);

    // Remove duplicates from the array
    n = removeDuplicates(arr, n);

    // Display the array after removing duplicates
    printf("Array after removing duplicates:\n");
    displayArray(arr, n);

    return 0;
}