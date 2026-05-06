#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    return (q->r == q->f);
}

int isFull(struct queue *q){
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }

    q->r++;
    q->arr[q->r] = val;

    printf("Enqueued: %d\n", val);
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    q->f++;
    return q->arr[q->f];
}

void display(struct queue *q){
    printf("\nQueue elements:\n");

    for(int i = q->f + 1; i <= q->r; i++){
        printf("%d\n", q->arr[i]);
    }
}

int main(){

    struct queue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 18);

    display(&q);

    printf("\nDequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

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