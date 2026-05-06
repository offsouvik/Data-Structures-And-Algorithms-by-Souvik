#include<stdio.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

void selectionSort(int *A, int n){

    int indexOfMin, temp;

    printf("\nRunning Selection Sort...\n");

    for(int i = 0; i < n - 1; i++){

        indexOfMin = i;

        printf("\nPass %d\n", i + 1);
        printf("Assuming minimum element = %d\n", A[indexOfMin]);

        for(int j = i + 1; j < n; j++){

            if(A[j] < A[indexOfMin]){

                indexOfMin = j;

                printf("New minimum found = %d\n", A[indexOfMin]);
            }
        }

        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;

        printf("Array after pass %d:\n", i + 1);
        printArray(A, n);
    }
}

int main(){

    int A[] = {64, 25, 12, 22, 11, 90, 5, 77};
    int n = 8;

    printf("Original Array:\n");
    printArray(A, n);

    selectionSort(A, n);

    printf("\nSorted Array:\n");
    printArray(A, n);

    return 0;
}