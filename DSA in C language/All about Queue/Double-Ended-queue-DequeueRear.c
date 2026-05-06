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

    de.arr[0] = 11;
    de.arr[1] = 22;
    de.arr[2] = 33;
    de.arr[3] = 44;
    de.arr[4] = 55;
    de.arr[5] = 66;
    de.arr[6] = 77;
    de.arr[7] = 88;

    printf("Removed from Rear: %d\n", dequeueRear(&de));
    printf("Removed from Rear: %d\n", dequeueRear(&de));

    display(&de);

    return 0;
}