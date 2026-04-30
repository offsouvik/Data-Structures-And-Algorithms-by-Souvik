#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteByValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q != NULL && q->data != value){
        p = p->next;
        q = q->next;
    }

    if(q != NULL){
        p->next = q->next;
        free(q);
    }

    return head;
}

int main(){

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 4; head->next = second;
    second->data = 3; second->next = third;
    third->data = 8; third->next = NULL;

    printf("Before deletion:\n");
    linkedListTraversal(head);

    head = deleteByValue(head, 3);

    printf("\nAfter deleting value:\n");
    linkedListTraversal(head);

    return 0;
}