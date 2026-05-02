#include <stdio.h>
#include <stdlib.h>

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
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(!isEmpty(ptr)){
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    return '\0';
}

int match(char a, char b){
    if(a=='{' && b=='}') return 1;
    if(a=='(' && b==')') return 1;
    if(a=='[' && b==']') return 1;
    return 0;
}

int parenthesisMatch(char *exp){
    struct stack* sp = malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)) return 0;
            char popped = pop(sp);
            if(!match(popped, exp[i])) return 0;
        }
    }

    return isEmpty(sp);
}

int main(){
    char *exp = "[4-6]((8){(9-8)})";

    if(parenthesisMatch(exp))
        printf("Parenthesis is balanced\n");
    else
        printf("Parenthesis is not balanced\n");

    return 0;
}