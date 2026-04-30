#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traverse(struct Node *head){
    if(head == NULL) return;
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

struct Node* deleteFirst(struct Node *head){
    if(head == NULL) return NULL;

    // Single node case
    if(head->next == head){
        free(head);
        return NULL;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
    return head;
}

int main(){

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 4; second->data = 3; third->data = 6;

    head->next = second; second->next = third; third->next = head;
    head->prev = third;  second->prev = head; third->prev = second;

    printf("Before:\n"); traverse(head);

    head = deleteFirst(head);

    printf("After:\n"); traverse(head);
}