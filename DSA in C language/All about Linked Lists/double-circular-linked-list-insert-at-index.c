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

struct Node* insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = malloc(sizeof(struct Node));
    struct Node *p = head;

    for(int i=0; i<index-1; i++){
        p = p->next;
    }

    ptr->data = data;

    ptr->next = p->next;
    ptr->prev = p;

    p->next->prev = ptr;
    p->next = ptr;

    return head;
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

    head = insertAtIndex(head, 55, 1);

    printf("After:\n");
    traverse(head);
}