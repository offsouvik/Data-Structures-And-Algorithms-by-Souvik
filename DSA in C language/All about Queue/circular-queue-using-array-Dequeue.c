#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q){
    return (q->r == q->f);
}

int dequeue(struct circularQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    q->f = (q->f + 1) % q->size;
    return q->arr[q->f];
}

void display(struct circularQueue *q){
    int i = (q->f + 1) % q->size;

    printf("\nCurrent Queue:\n");

    while(i != (q->r + 1) % q->size){
        printf("%d\n", q->arr[i]);
        i = (i + 1) % q->size;
    }
}

int main(){

    struct circularQueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    q.r = (q.r + 1) % q.size;
    q.arr[q.r] = 10;

    q.r = (q.r + 1) % q.size;
    q.arr[q.r] = 20;

    q.r = (q.r + 1) % q.size;
    q.arr[q.r] = 30;

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    return 0;
}