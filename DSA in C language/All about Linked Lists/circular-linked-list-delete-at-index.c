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

struct Node* deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i=0; i<index-1; i++){
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
    third->data = 6; third->next = head;

    printf("Before:\n");
    traverse(head);

    head = deleteAtIndex(head, 1);

    printf("After:\n");
    traverse(head);
}