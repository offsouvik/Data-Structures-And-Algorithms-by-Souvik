#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

struct Node* push(struct Node* top, int x){
    struct Node* n = malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack Overflow\n");
        return top;
    }
    n->data = x;
    n->next = top;
    return n;
}

int stackTop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main(){
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Top element: %d\n", stackTop());

    return 0;
}