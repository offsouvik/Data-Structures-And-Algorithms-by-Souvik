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

void display(){
    struct Node *ptr = f;

    printf("\nQueue Elements:\n");

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    return 0;
}