#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

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

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    return 0;
}