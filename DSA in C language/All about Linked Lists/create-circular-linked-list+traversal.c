#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Traversal function
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;

    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Create circular linked list
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printf("Traversal of Circular Linked List:\n");
    linkedListTraversal(head);

    return 0;
}