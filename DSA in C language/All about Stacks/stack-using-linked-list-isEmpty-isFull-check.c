#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node* top){
    return (top == NULL);
}

int isFull(struct Node* top){
    struct Node* p = malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    free(p);
    return 0;
}

int main(){
    struct Node* top = NULL;

    printf("Checking stack state:\n");

    if(isEmpty(top))
        printf("Stack is EMPTY\n");
    else
        printf("Stack is NOT EMPTY\n");

    if(isFull(top))
        printf("Stack is FULL\n");
    else
        printf("Stack has available space\n");

    return 0;
}