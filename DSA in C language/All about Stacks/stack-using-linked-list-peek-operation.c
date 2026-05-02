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

int peek(int pos){
    struct Node* ptr = top;

    for(int i = 0; i < pos - 1 && ptr != NULL; i++){
        ptr = ptr->next;
    }

    if(ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int main(){
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    for(int i = 1; i <= 4; i++){
        printf("Value at position %d: %d\n", i, peek(i));
    }

    return 0;
}