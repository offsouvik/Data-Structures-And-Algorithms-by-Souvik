#include<stdio.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

void insertionSort(int *A, int n){

    int key, j;

    for(int i = 1; i <= n - 1; i++){

        key = A[i];
        j = i - 1;

        printf("\nPass %d\n", i);
        printf("Current key = %d\n", key);

        while(j >= 0 && A[j] > key){

            A[j + 1] = A[j];

            printf("Shifting %d to position %d\n", A[j], j + 1);

            j--;
        }

        A[j + 1] = key;

        printf("Inserted %d at position %d\n", key, j + 1);

        printf("Array after pass %d:\n", i);
        printArray(A, n);
    }
}

int main(){

    int A[] = {12, 54, 65, 7, 23, 9, 100, 2, 88};
    int n = 9;

    printf("Original Array:\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("\nSorted Array:\n");
    printArray(A, n);

    return 0;
}