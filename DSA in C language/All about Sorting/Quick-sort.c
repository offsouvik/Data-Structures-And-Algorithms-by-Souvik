#include<stdio.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

int partition(int A[], int low, int high){

    int pivot = A[low];

    int i = low + 1;
    int j = high;

    int temp;

    printf("\n---------------------------------\n");
    printf("Current Pivot = %d\n", pivot);
    printf("Subarray Range = %d to %d\n", low, high);

    do{

        while(A[i] <= pivot && i <= high){
            i++;
        }

        while(A[j] > pivot){
            j--;
        }

        if(i < j){

            printf("\nSwapping %d and %d\n", A[i], A[j]);

            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            printf("Array after swapping:\n");
            printArray(A, 10);
        }

    }while(i < j);

    printf("\nSwapping Pivot %d with %d\n", A[low], A[j]);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    printf("Array after placing pivot:\n");
    printArray(A, 10);

    printf("Pivot %d placed at index %d\n", A[j], j);

    return j;
}

void quickSort(int A[], int low, int high){

    int partitionIndex;

    if(low < high){

        partitionIndex = partition(A, low, high);

        printf("\nLeft Side Sorting: low = %d , high = %d\n",
               low, partitionIndex - 1);

        quickSort(A, low, partitionIndex - 1);

        printf("\nRight Side Sorting: low = %d , high = %d\n",
               partitionIndex + 1, high);

        quickSort(A, partitionIndex + 1, high);
    }
}

int main(){

    int A[] = {9, 4, 4, 8, 7, 5, 6, 2, 1, 10};

    int n = 10;

    printf("Before Sorting:\n");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("\n=================================\n");
    printf("Final Sorted Array:\n");

    printArray(A, n);

    return 0;
}