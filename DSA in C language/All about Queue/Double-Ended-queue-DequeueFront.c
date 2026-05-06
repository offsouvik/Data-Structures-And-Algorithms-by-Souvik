#include<stdio.h>
#include<stdlib.h>

struct doubleEndedQueue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct doubleEndedQueue *de){
    return (de->front == -1);
}

int dequeueFront(struct doubleEndedQueue *de){

    if(isEmpty(de)){
        printf("Double Ended Queue is Empty\n");
        return -1;
    }

    int val = de->arr[de->front];

    if(de->front == de->rear){
        de->front = de->rear = -1;
    }
    else if(de->front == de->size - 1){
        de->front = 0;
    }
    else{
        de->front++;
    }

    return val;
}

void display(struct doubleEndedQueue *de){

    int i = de->front;

    printf("\nRemaining Elements:\n");

    while(1){

        printf("%d\n", de->arr[i]);

        if(i == de->rear)
            break;

        i = (i + 1) % de->size;
    }
}

int main(){

    struct doubleEndedQueue de;

    de.size = 15;
    de.front = 0;
    de.rear = 7;

    de.arr = malloc(de.size * sizeof(int));

    de.arr[0] = 10;
    de.arr[1] = 20;
    de.arr[2] = 30;
    de.arr[3] = 40;
    de.arr[4] = 50;
    de.arr[5] = 60;
    de.arr[6] = 70;
    de.arr[7] = 80;

    printf("Removed from Front: %d\n", dequeueFront(&de));
    printf("Removed from Front: %d\n", dequeueFront(&de));

    display(&de);

    return 0;
}