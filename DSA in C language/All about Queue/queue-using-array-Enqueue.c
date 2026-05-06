#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

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

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    return 0;
}