#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nResult of Matrix Addition:\n");
    displayMatrix(result, rows, cols);
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2) {
    int result[MAX][MAX];

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    displayMatrix(result, r1, c2);
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transpose[MAX][MAX];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of Matrix:\n");
    displayMatrix(transpose, cols, rows);
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    int choice;

    printf("=== Matrix Operations Program ===\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter rows and columns for matrices: ");
            scanf("%d %d", &rows1, &cols1);

            printf("Enter elements of Matrix A:\n");
            inputMatrix(A, rows1, cols1);

            printf("Enter elements of Matrix B:\n");
            inputMatrix(B, rows1, cols1);

            addMatrix(A, B, rows1, cols1);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &rows1, &cols1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &rows2, &cols2);

            if(cols1 != rows2) {
                printf("Matrix multiplication not possible!\n");
            } else {
                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, rows1, cols1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, rows2, cols2);

                multiplyMatrix(A, B, rows1, cols1, cols2);
            }
            break;

        case 3:
            printf("Enter rows and columns of Matrix: ");
            scanf("%d %d", &rows1, &cols1);

            printf("Enter elements of Matrix:\n");
            inputMatrix(A, rows1, cols1);

            transposeMatrix(A, rows1, cols1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}