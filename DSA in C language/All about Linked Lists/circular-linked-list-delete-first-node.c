#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

void traverse(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

struct Node* deleteFirst(struct Node *head){
    struct Node *p = head;
    struct Node *q = head;

    while(q->next != head){
        q = q->next;
    }

    head = head->next;
    q->next = head;
    free(p);

    return head;
}

int main(){

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 4; head->next = second;
    second->data = 3; second->next = third;
    third->data = 6; third->next = head;

    printf("Before:\n");
    traverse(head);

    head = deleteFirst(head);

    printf("After:\n");
    traverse(head);
}