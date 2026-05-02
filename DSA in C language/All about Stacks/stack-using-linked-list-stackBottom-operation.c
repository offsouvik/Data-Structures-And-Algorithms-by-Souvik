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

int stackBottom(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }

    struct Node* ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Bottom element: %d\n", stackBottom());

    return 0;
}