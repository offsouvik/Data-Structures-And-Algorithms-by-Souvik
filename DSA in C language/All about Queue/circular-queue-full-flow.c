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

int isFull(struct circularQueue *q){
    return ((q->r + 1) % q->size == q->f);
}

void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }

    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = val;

    printf("Enqueued: %d\n", val);
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

    printf("\nQueue elements:\n");

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

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 18);

    display(&q);

    printf("\nDequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 45);
    enqueue(&q, 50);

    display(&q);

    if(isEmpty(&q))
        printf("\nQueue is empty\n");
    else
        printf("\nQueue is not empty\n");

    if(isFull(&q))
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");

    return 0;
}