#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    return (ptr->top == -1);
}

int isFull(struct stack *ptr){
    return (ptr->top == ptr->size - 1);
}

void push(struct stack* ptr, char val){
    if(!isFull(ptr)){
        ptr->arr[++ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(!isEmpty(ptr)){
        return ptr->arr[ptr->top--];
    }
    return '\0';
}

char stackTop(struct stack* sp){
    if(isEmpty(sp)) return '\0';
    return sp->arr[sp->top];
}

int precedence(char ch){
    if(ch == '*' || ch=='/') return 3;
    else if(ch == '+' || ch=='-') return 2;
    return 0;
}

int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

char* infixToPostfix(char* infix){
    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(char));

    char *postfix = malloc((strlen(infix)+1) * sizeof(char));

    int i = 0, j = 0;

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            while(!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))){
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }

    while(!isEmpty(sp)){
        postfix[j++] = pop(sp);
    }

    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *infix = "x-y/z-k*d";
    printf("Postfix: %s\n", infixToPostfix(infix));
    return 0;
}