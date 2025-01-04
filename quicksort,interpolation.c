//Write a C program to sort an unsorted array using recursive Quick Sort algo and after sorting return the index position of third highest number using Interpolation Search. 

#include <stdio.h>

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index for the smaller element

    // Traverse through the array and rearrange elements
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // Return the partition index
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function for Interpolation Search
int interpolationSearch(int arr[], int low, int high, int key) {
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Calculate the probe position
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // If the key is found at the probe position
        if (arr[pos] == key) {
            return pos;
        }

        // If the key is smaller, ignore the right half
        if (arr[pos] > key) {
            high = pos - 1;
        }
        // If the key is larger, ignore the left half
        else {
            low = pos + 1;
        }
    }
    return -1;  // If the element is not found
}

int main() {
    int n;

    // Take user input for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take user input for the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Step 2: Find the third highest element using Interpolation Search
    if (n >= 3) {
        int thirdHighest = arr[n - 3];
        printf("The third highest element is: %d\n", thirdHighest);

        // Step 3: Find the index of the third highest element using Interpolation Search
        int index = interpolationSearch(arr, 0, n - 1, thirdHighest);

        if (index != -1) {
            printf("The index of the third highest element (%d) is: %d\n", thirdHighest, index);
        } else {
            printf("Element not found in the array.\n");
        }
    } else {
        printf("Array must contain at least 3 elements.\n");
    }

    return 0;
}