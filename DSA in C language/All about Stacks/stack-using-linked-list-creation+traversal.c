#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

void linkedListTraversal(struct Node *ptr){
    printf("Stack (Top -> Bottom):\n");
    while(ptr != NULL){
        printf("| %d |\n", ptr->data);
        printf("-----\n");
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;

    top = n1;

    linkedListTraversal(top);

    return 0;
}