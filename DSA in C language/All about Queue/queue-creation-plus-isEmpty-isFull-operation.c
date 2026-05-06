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

int main(){

    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    printf("isEmpty: %d\n", isEmpty(&q));
    printf("isFull : %d\n", isFull(&q));

    return 0;
}