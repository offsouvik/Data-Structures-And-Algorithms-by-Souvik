#include<stdio.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

void bubbleSort(int *A, int n){

    int temp;

    for(int i = 0; i < n - 1; i++){

        printf("\nWorking on Pass %d\n", i + 1);

        for(int j = 0; j < n - 1 - i; j++){

            if(A[j] > A[j + 1]){

                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }

        printArray(A, n);
    }
}

int main(){

    int A[] = {64, 34, 25, 12, 22, 11, 90, 55, 77};
    int n = 9;

    printf("Before Sorting:\n");
    printArray(A, n);

    bubbleSort(A, n);

    printf("\nAfter Sorting:\n");
    printArray(A, n);

    return 0;
}