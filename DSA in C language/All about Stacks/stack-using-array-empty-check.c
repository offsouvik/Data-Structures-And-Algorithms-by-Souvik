#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    return (ptr->top == -1);
}

int main(){

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    if(isEmpty(s)){
        printf("The stack is empty\n");
    } else{
        printf("The stack is not empty\n");
    }

    return 0;
}