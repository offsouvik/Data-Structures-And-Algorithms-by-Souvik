#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack* ptr){
    return (ptr->top == ptr->size - 1);
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Overflow! Cannot push %d\n", val);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    printf("Pushed: %d\n", val);
}

// 🔵 Display function
void display(struct stack* ptr){
    if(ptr->top == -1){
        printf("Stack is empty\n");
        return;
    }

    printf("\nStack elements (top to bottom):\n");
    for(int i = ptr->top; i >= 0; i--){
        printf("%d\n", ptr->arr[i]);
    }
}

int main(){

    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(int));

    push(sp, 10);
    push(sp, 20);
    push(sp, 30);

    // Print full stack
    display(sp);

    return 0;
}