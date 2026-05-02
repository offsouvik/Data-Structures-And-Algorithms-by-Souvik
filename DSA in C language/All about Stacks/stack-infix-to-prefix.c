#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *sp){
    return sp->top == -1;
}

void push(struct stack *sp, char ch){
    sp->arr[++sp->top] = ch;
}

char pop(struct stack *sp){
    if(isEmpty(sp)) return '\0';
    return sp->arr[sp->top--];
}

char stackTop(struct stack *sp){
    if(isEmpty(sp)) return '\0';
    return sp->arr[sp->top];
}

int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

int precedence(char ch){
    if(ch=='*' || ch=='/') return 3;
    else if(ch=='+' || ch=='-') return 2;
    return 0;
}

void reverse(char *exp){
    int n = strlen(exp);
    for(int i = 0; i < n/2; i++){
        char temp = exp[i];
        exp[i] = exp[n-i-1];
        exp[n-i-1] = temp;
    }
}

void swapBrackets(char *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(') exp[i] = ')';
        else if(exp[i] == ')') exp[i] = '(';
    }
}

char* infixToPrefix(char *infix){
    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(char));

    char *postfix = malloc(strlen(infix)+1);

    reverse(infix);
    swapBrackets(infix);

    int i = 0, j = 0;

    while(infix[i] != '\0'){
        if(!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')'){
            postfix[j++] = infix[i++];
        }
        else if(infix[i] == '('){
            push(sp, infix[i++]);
        }
        else if(infix[i] == ')'){
            while(!isEmpty(sp) && stackTop(sp) != '('){
                postfix[j++] = pop(sp);
            }
            pop(sp);
            i++;
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

    reverse(postfix);
    return postfix;
}

int main(){
    char infix[] = "(a-b/c)*(a/k-l)";
    printf("Prefix: %s\n", infixToPrefix(infix));
    return 0;
}