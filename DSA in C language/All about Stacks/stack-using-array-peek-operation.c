#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

// Peek: i = 1 means TOP element
int peek(struct stack* sp, int i){
    int arrayInd = sp->top - i + 1;

    if(arrayInd < 0 || arrayInd > sp->top){
        printf("Peek(%d): Invalid position\n", i);
        return -1;
    }
    return sp->arr[arrayInd];
}

// Display full stack
void display(struct stack* sp){
    if(sp->top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack (top -> bottom):\n");
    for(int i = sp->top; i >= 0; i--){
        printf("Index %d : %d\n", i, sp->arr[i]);
    }
}

int main(){

    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(int));

    // preload more values
    sp->arr[++sp->top] = 5;
    sp->arr[++sp->top] = 10;
    sp->arr[++sp->top] = 15;
    sp->arr[++sp->top] = 20;
    sp->arr[++sp->top] = 25;

    display(sp);

    printf("\n--- Peek Results ---\n");
    printf("Peek(1) [Top]       : %d\n", peek(sp, 1));
    printf("Peek(2)             : %d\n", peek(sp, 2));
    printf("Peek(3)             : %d\n", peek(sp, 3));
    printf("Peek(5) [Bottom]    : %d\n", peek(sp, 5));
    printf("Peek(6) [Invalid]   : %d\n", peek(sp, 6));

    return 0;
}