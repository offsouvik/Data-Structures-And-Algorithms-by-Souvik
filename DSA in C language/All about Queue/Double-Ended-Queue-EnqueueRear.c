#include<stdio.h>
#include<stdlib.h>

struct doubleEndedQueue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct doubleEndedQueue *de){
    return ((de->front == 0 && de->rear == de->size - 1) ||
            (de->front == de->rear + 1));
}

void enqueueRear(struct doubleEndedQueue *de, int val){

    if(isFull(de)){
        printf("Double Ended Queue is Full\n");
        return;
    }

    if(de->front == -1){
        de->front = de->rear = 0;
    }
    else if(de->rear == de->size - 1){
        de->rear = 0;
    }
    else{
        de->rear++;
    }

    de->arr[de->rear] = val;

    printf("Inserted at Rear: %d\n", val);
}

void display(struct doubleEndedQueue *de){

    int i = de->front;

    printf("\nDouble Ended Queue Elements:\n");

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
    de.front = de.rear = -1;

    de.arr = malloc(de.size * sizeof(int));

    enqueueRear(&de, 5);
    enqueueRear(&de, 15);
    enqueueRear(&de, 25);
    enqueueRear(&de, 35);
    enqueueRear(&de, 45);
    enqueueRear(&de, 55);
    enqueueRear(&de, 65);

    display(&de);

    return 0;
}