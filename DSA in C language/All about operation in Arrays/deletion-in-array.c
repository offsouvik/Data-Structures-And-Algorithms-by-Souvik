#include<stdio.h>
void display(int arr[], int n){
    //code for traversal
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index){
    //code for Deletion at index
    for(int i = index; i < size-1; i++){
       arr[i] = arr[i+1];
    }
}

int main(){
    int arr[100] = {7, 8, 12, 27, 38};
    int size = 5,element =25,index=1;
    printf("Before deletion: ");

    display(arr, size);

    indDeletion(arr, size, index);
    size -=1;
    printf("After deletion: ");
    display(arr, size);
    
    return 0;
}