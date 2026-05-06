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

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    q->f++;
    return q->arr[q->f];
}

void display(struct queue *q){
    printf("\nCurrent Queue:\n");

    for(int i = q->f + 1; i <= q->r; i++){
        printf("%d\n", q->arr[i]);
    }
}

int main(){

    struct queue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    q.arr[++q.r] = 10;
    q.arr[++q.r] = 20;
    q.arr[++q.r] = 30;

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    return 0;
}