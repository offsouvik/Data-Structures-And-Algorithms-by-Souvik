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

    enqueueFront(&de, 10);
    enqueueFront(&de, 20);
    enqueueFront(&de, 30);
    enqueueFront(&de, 40);
    enqueueFront(&de, 50);

    display(&de);

    return 0;
}