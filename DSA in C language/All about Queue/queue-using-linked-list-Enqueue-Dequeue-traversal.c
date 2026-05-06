#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueue(int val){

    struct Node *n = malloc(sizeof(struct Node));

    if(n == NULL){
        printf("Queue is Full\n");
        return;
    }

    n->data = val;
    n->next = NULL;

    if(f == NULL){
        f = r = n;
    }
    else{
        r->next = n;
        r = n;
    }

    printf("Enqueued: %d\n", val);
}

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

    printf("\nQueue Elements:\n");

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);

    display();

    printf("\nDequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}