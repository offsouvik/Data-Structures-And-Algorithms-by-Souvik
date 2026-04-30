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

struct Node * deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
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

    head = deleteFirst(head);

    printf("\nAfter deleting first node:\n");
    linkedListTraversal(head);

    return 0;
}