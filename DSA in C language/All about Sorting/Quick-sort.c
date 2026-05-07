#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int *A, int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

int maximum(int A[], int n){

    int max = INT_MIN;

    for(int i = 0; i < n; i++){

        if(max < A[i]){
            max = A[i];
        }
    }

    return max;
}

void countSort(int *A, int n){

    int i, j;

    int max = maximum(A, n);

    printf("\nMaximum Element = %d\n", max);

    int *count = (int *) malloc((max + 1) * sizeof(int));

    for(i = 0; i < max + 1; i++){
        count[i] = 0;
    }

    printf("\nCounting Frequencies:\n");

    for(i = 0; i < n; i++){

        count[A[i]]++;

        printf("Element %d Frequency = %d\n",
               A[i],
               count[A[i]]);
    }

    i = 0;
    j = 0;

    while(i <= max){

        if(count[i] > 0){

            A[j] = i;

            count[i]--;

            j++;
        }
        else{
            i++;
        }
    }
}

int main(){

    int A[] = {9, 1, 4, 14, 4, 15, 6, 3, 2, 9, 1};

    int n = 11;

    printf("Before Sorting:\n");
    printArray(A, n);

    countSort(A, n);

    printf("\nAfter Sorting:\n");
    printArray(A, n);

    return 0;
}