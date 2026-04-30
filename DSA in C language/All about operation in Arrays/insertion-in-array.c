#include<stdio.h>
void display(int arr[], int n){
    //code for traversal
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    //code for insertion at index
    if(size >= capacity){
        printf("Array is full. Cannot insert element.\n");
        return -1;
    }
    for(int i = size-1; i >= index; i--){
       arr[i + 1] = arr[i];
    }
    
   
    arr[index] = element;
    
    return 1; 

}

int main(){
    int arr[100] = {7, 8, 12, 27, 38};
    int size = 5,element =25,index=1;
    printf("Before insertion: ");

    display(arr, size);

    indInsertion(arr, size, element , 100, index);
    size+=1;
    printf("After insertion: ");
    display(arr, size);
    
    return 0;
}