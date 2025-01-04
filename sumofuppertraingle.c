//  Write a C program to calculate the sum of upper triangular matrix. 

#include <stdio.h>

int main() {
    int n, i, j, sum = 0;

    // Input the size of the matrix
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Element at position (%d,%d): ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the upper triangular matrix
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) { // Only process elements where i <= j
            sum += matrix[i][j];
        }
    }

    // Output the result
    printf("Sum of the upper triangular matrix: %d\n", sum);

    return 0;
}