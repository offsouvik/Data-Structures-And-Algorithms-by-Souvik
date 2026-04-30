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

struct Node* deleteLast(struct Node *head){
    if(head == NULL) return NULL;

    if(head->next == head){
        free(head);
        return NULL;
    }

    struct Node *last = head->prev;

    last->prev->next = head;
    head->prev = last->prev;

    free(last);
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

    head = deleteLast(head);

    printf("After:\n"); traverse(head);
}