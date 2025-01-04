// Write a C program to sort an unsorted array using recursive Quick Sort algo then 
//choose another element which you have not used as a pivot element, and check this 
//element is present in same array or not using binary search. 

#include <stdio.h>

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);  // Place the pivot in the correct position
    return (i + 1);  // Return the pivot index
}

// Quick Sort function (recursive)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort the two subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search function
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is greater, ignore the left half
        if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1;  // Key is not present
}

int main() {
    int n;

    // Take user input for the array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take user input for the array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter an element to search in the sorted array: ");
    scanf("%d", &key);

    // Perform binary search to find the element
    int result = binarySearch(arr, 0, n - 1, key);

    // Output the result of the binary search
    if (result != -1) {
        printf("Element %d is present at index %d.\n", key, result);
    } else {
        printf("Element %d is not present in the array.\n", key);
    }

    return 0;
}