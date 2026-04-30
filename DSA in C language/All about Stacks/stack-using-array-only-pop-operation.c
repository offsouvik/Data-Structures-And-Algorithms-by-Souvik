#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr){
    return (ptr->top == -1);
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Underflow!\n");
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

// Display full stack
void display(struct stack* ptr){
    if(ptr->top == -1){
        printf("Stack is empty\n");
        return;
    }

    printf("\nCurrent Stack (top to bottom):\n");
    for(int i = ptr->top; i >= 0; i--){
        printf("%d\n", ptr->arr[i]);
    }
}

int main(){

    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 10;   // 🔥 bigger size
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(int));

    //  preload more elements
    sp->arr[++sp->top] = 5;
    sp->arr[++sp->top] = 10;
    sp->arr[++sp->top] = 15;
    sp->arr[++sp->top] = 20;
    sp->arr[++sp->top] = 25;
    sp->arr[++sp->top] = 30;
    sp->arr[++sp->top] = 35;

    printf("Initial Stack:");
    display(sp);

    printf("\nPopped: %d\n", pop(sp));
    printf("Popped: %d\n", pop(sp));
    printf("Popped: %d\n", pop(sp));

    // 🔽 After popping
    display(sp);

    return 0;
}