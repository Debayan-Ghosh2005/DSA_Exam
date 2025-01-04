// Write a C program for recursive Bubble Sort, Insertion Sort, Selection Sort, Merge Sort. 
//Input: 50.987654321, -60.15, 2, 232.987456, -99999999.9999, 21, 7.65435679, 
//123.35, 88, -987 
//Output: -99999999.99, -987.00, -123.35, -60.15, 2.00, 7.65, 21.00, 50.98, 88.00, 232.98

#include <stdio.h>
#include <math.h>

// Utility function to display the array
void display(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", round(arr[i] * 100) / 100);
    }
    printf("\n");
}

// Recursive Bubble Sort
void bubbleSort(float arr[], int n) {
    if (n == 1) return;
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            float temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, n - 1);
}

// Recursive Insertion Sort
void insertionSort(float arr[], int n) {
    if (n <= 1) return;

    insertionSort(arr, n - 1);
    
    float key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Recursive Selection Sort
void selectionSort(float arr[], int n, int index) {
    if (index == n) return;

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
    }

    float temp = arr[minIndex];
    arr[minIndex] = arr[index];
    arr[index] = temp;

    selectionSort(arr, n, index + 1);
}

// Merge Sort (Helper: Merge)
void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    float leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }
    
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// Recursive Merge Sort
void mergeSort(float arr[], int left, int right) {
    if (left >= right) return;
    
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;

    // User input for the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    // User input for the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original Array:\n");
    display(arr, n);

    // Uncomment the sorting algorithm you want to use:

    // bubbleSort(arr, n);        // Use Recursive Bubble Sort
    // insertionSort(arr, n);     // Use Recursive Insertion Sort
    // selectionSort(arr, n, 0);  // Use Recursive Selection Sort
    mergeSort(arr, 0, n - 1);   // Use Recursive Merge Sort

    printf("\nSorted Array:\n");
    display(arr, n);

    return 0;
}