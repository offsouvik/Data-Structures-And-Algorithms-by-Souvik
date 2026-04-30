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

struct Node* deleteByValue(struct Node *head, int value){
    if(head == NULL) return NULL;

    struct Node *p = head;

    do{
        if(p->data == value){

            if(p->next == p){ // single node
                free(p);
                return NULL;
            }

            if(p == head){
                struct Node *last = head->prev;
                head = head->next;
                head->prev = last;
                last->next = head;
                free(p);
                return head;
            }

            p->prev->next = p->next;
            p->next->prev = p->prev;

            free(p);
            return head;
        }
        p = p->next;
    }while(p != head);

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

    head = deleteByValue(head, 3);

    printf("After:\n"); traverse(head);
}