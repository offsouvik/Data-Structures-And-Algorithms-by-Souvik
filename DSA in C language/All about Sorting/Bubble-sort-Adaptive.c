#include<stdio.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

void bubbleSortAdaptive(int *A, int n){

    int temp;
    int isSorted;

    for(int i = 0; i < n - 1; i++){

        printf("\nWorking on Pass %d\n", i + 1);

        isSorted = 1;

        for(int j = 0; j < n - 1 - i; j++){

            if(A[j] > A[j + 1]){

                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

                isSorted = 0;
            }
        }

        printArray(A, n);

        if(isSorted){

            printf("\nArray already sorted\n");
            return;
        }
    }
}

int main(){

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;

    printf("Before Sorting:\n");
    printArray(A, n);

    bubbleSortAdaptive(A, n);

    printf("\nAfter Sorting:\n");
    printArray(A, n);

    return 0;
}