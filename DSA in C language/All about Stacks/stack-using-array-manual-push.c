#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int main(){

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Manual push
    s->top++;
    s->arr[s->top] = 100;
    s->top++;
    s->arr[s->top] = 10;
    s->top++;
    s->arr[s->top] = 1;
    s->top++;
    s->arr[s->top] = 11;
    s->top++;
    s->arr[s->top] = 12;
    
    printf("Pushed element: %d\n", s->arr[s->top]);
    printf("Top index: %d\n", s->top);

    return 0;
}