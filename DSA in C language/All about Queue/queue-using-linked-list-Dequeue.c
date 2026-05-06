#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

int dequeue(){

    if(f == NULL){
        printf("Queue is Empty\n");
        return -1;
    }

    struct Node *ptr = f;
    int val = ptr->data;

    f = f->next;
    free(ptr);

    return val;
}

void display(){
    struct Node *ptr = f;

    printf("\nCurrent Queue:\n");

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = NULL;

    f = n1;
    r = n3;

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}