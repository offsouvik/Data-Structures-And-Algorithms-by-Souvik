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

int isFull(struct doubleEndedQueue *de){
    return ((de->front == 0 && de->rear == de->size - 1) ||
            (de->front == de->rear + 1));
}

void enqueueFront(struct doubleEndedQueue *de, int val){

    if(isFull(de)){
        printf("Double Ended Queue is Full\n");
        return;
    }

    if(de->front == -1){
        de->front = de->rear = 0;
    }
    else if(de->front == 0){
        de->front = de->size - 1;
    }
    else{
        de->front--;
    }

    de->arr[de->front] = val;

    printf("Inserted at Front: %d\n", val);
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

int dequeueRear(struct doubleEndedQueue *de){

    if(isEmpty(de)){
        printf("Double Ended Queue is Empty\n");
        return -1;
    }

    int val = de->arr[de->rear];

    if(de->front == de->rear){
        de->front = de->rear = -1;
    }
    else if(de->rear == 0){
        de->rear = de->size - 1;
    }
    else{
        de->rear--;
    }

    return val;
}

void display(struct doubleEndedQueue *de){

    if(isEmpty(de)){
        printf("Double Ended Queue is Empty\n");
        return;
    }

    int i = de->front;

    printf("\nCurrent Double Ended Queue:\n");

    while(1){

        printf("%d\n", de->arr[i]);

        if(i == de->rear)
            break;

        i = (i + 1) % de->size;
    }
}

int main(){

    struct doubleEndedQueue de;

    de.size = 20;
    de.front = de.rear = -1;

    de.arr = malloc(de.size * sizeof(int));

    enqueueRear(&de, 10);
    enqueueRear(&de, 20);
    enqueueRear(&de, 30);
    enqueueRear(&de, 40);

    enqueueFront(&de, 5);
    enqueueFront(&de, 2);
    enqueueFront(&de, 1);

    printf("\nRemoved from Front: %d\n", dequeueFront(&de));
    printf("Removed from Rear : %d\n", dequeueRear(&de));

    enqueueRear(&de, 50);
    enqueueRear(&de, 60);

    display(&de);

    return 0;
}