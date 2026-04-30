#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traverse(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

struct Node* insertAtFirst(struct Node *head, int data){
    struct Node *ptr = malloc(sizeof(struct Node));
    struct Node *last = head->prev;

    ptr->data = data;

    ptr->next = head;
    ptr->prev = last;

    head->prev = ptr;
    last->next = ptr;

    return ptr;
}

int main(){

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 4;
    second->data = 3;
    third->data = 6;

    head->next = second;
    second->next = third;
    third->next = head;

    head->prev = third;
    second->prev = head;
    third->prev = second;

    printf("Before:\n");
    traverse(head);

    head = insertAtFirst(head, 99);

    printf("After:\n");
    traverse(head);
}