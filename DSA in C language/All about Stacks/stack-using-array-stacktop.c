#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

void push(struct stack* ptr, int val){
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int stackTop(struct stack* sp){
    if(sp->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return sp->arr[sp->top];
}

int main(){

    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(int));

    // push values
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);

    printf("Top element of stack: %d\n", stackTop(sp));

    return 0;
}