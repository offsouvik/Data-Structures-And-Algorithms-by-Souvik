#include<stdio.h>

int binarySearch(int arr[], int size, int element){
    int low = 0;
    int high = size - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == element){
            return mid;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;

    int searchIndex = binarySearch(arr, size, element);

    if(searchIndex != -1)
        printf("Element %d found at index %d\n", element, searchIndex);
    else
        printf("Element %d not found\n", element);

    return 0;
}