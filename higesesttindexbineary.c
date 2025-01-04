// Write a C Program to find the index position of third highest negative number using binary search.

#include <stdio.h>

// Function for Binary Search to find the third highest negative number
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Return the index if the target is found
        }
        
        if (arr[mid] > target) {
            low = mid + 1;  // Target is smaller, so search the right half
        } else {
            high = mid - 1;  // Target is larger, so search the left half
        }
    }
    
    return -1;  // Target not found
}

// Function to find the index position of the third highest negative number
int findThirdHighestNegative(int arr[], int size) {
    int count = 0;  // To keep track of how many negative numbers we've encountered
    int thirdHighestIndex = -1;
    
    // Traverse the array in reverse to find negative numbers
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
            if (count == 3) {
                thirdHighestIndex = i;  // Store the index when the third negative number is found
                break;
            }
        }
    }

    return thirdHighestIndex;
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

    // Find the index position of the third highest negative number
    int index = findThirdHighestNegative(arr, n);

    if (index != -1) {
        printf("The third highest negative number is %d at index %d\n", arr[index], index);
    } else {
        printf("There are fewer than three negative numbers in the array.\n");
    }

    return 0;
}