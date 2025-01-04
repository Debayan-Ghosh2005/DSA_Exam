//Write a C program to count the frequency of each element of an array.  

#include <stdio.h>

void countFrequency(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 1;

        // Skip duplicates
        if (arr[i] == -1) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1; // Mark duplicate as processed
            }
        }

        printf("%d occurs %d times\n", arr[i], count);
    }
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count and display frequencies
    printf("\nElement frequencies:\n");
    countFrequency(arr, n);

    return 0;
}