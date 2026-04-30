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

struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
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

    head = deleteAtIndex(head, 1);

    printf("\nAfter deleting at index:\n");
    linkedListTraversal(head);

    return 0;
}