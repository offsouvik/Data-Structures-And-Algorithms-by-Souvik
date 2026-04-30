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

struct Node* insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = malloc(sizeof(struct Node));

    ptr->data = data;

    ptr->next = prevNode->next;
    ptr->prev = prevNode;

    prevNode->next->prev = ptr;
    prevNode->next = ptr;

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

    head = insertAfterNode(head, second, 88);

    printf("After:\n");
    traverse(head);
}