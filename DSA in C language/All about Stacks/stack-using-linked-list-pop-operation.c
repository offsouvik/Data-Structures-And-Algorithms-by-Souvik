#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node* top){
    return (top == NULL);
}

struct Node* pop(struct Node* top, int *popped){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        *popped = -1;
        return top;
    }

    struct Node* temp = top;
    *popped = temp->data;
    top = top->next;
    free(temp);

    return top;
}

void display(struct Node* top){
    printf("\nStack (Top -> Bottom):\n");
    while(top != NULL){
        printf("| %d |\n", top->data);
        printf("-----\n");
        top = top->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* top = NULL;
    int val;

    top = malloc(sizeof(struct Node));
    top->data = 10;
    top->next = NULL;

    struct Node* n2 = malloc(sizeof(struct Node));
    n2->data = 20;
    n2->next = top;
    top = n2;

    struct Node* n3 = malloc(sizeof(struct Node));
    n3->data = 30;
    n3->next = top;
    top = n3;

    printf("Before Pop:");
    display(top);

    top = pop(top, &val);
    printf("\nPopped Element: %d\n", val);

    printf("After Pop:");
    display(top);

    return 0;
}