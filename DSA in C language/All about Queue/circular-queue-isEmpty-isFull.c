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

int main(){

    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    printf("isEmpty: %d\n", isEmpty(&q));
    printf("isFull : %d\n", isFull(&q));

    return 0;
}