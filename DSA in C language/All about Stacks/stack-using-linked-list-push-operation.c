#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* push(struct Node* top, int x){
    struct Node* n = malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack Overflow\n");
        return top;
    }
    n->data = x;
    n->next = top;
    printf("Pushed: %d\n", x);
    return n;
}

void display(struct Node* top){
    printf("\nStack (Top -> Bottom):\n");
    while(top != NULL){
        printf("| %d |\n", top->data);
        printf("-----\n");
        top = top->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    display(top);

    return 0;
}