#include<stdio.h>
#include<malloc.h>

// Structure of a tree node
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data){

    struct node *n;

    // Memory allocation for new node
    n = (struct node *) malloc(sizeof(struct node));

    // Assigning data
    n->data = data;

    // Initially left and right child are NULL
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main(){

    // Creating root node
    struct node *p = createNode(10);

    // Creating second level nodes
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(15);

    // Creating third level nodes
    struct node *p3 = createNode(3);
    struct node *p4 = createNode(7);

    struct node *p5 = createNode(12);
    struct node *p6 = createNode(18);

    // Linking root node with left and right child
    p->left = p1;
    p->right = p2;

    // Linking left subtree
    p1->left = p3;
    p1->right = p4;

    // Linking right subtree
    p2->left = p5;
    p2->right = p6;

    // Printing root node
    printf("Root Node: %d\n", p->data);

    // Printing children of root node
    printf("\nLeft and Right Child of %d:\n", p->data);
    printf("Left Child = %d\n", p->left->data);
    printf("Right Child = %d\n", p->right->data);

    // Printing children of node 5
    printf("\nLeft and Right Child of %d:\n", p1->data);
    printf("Left Child = %d\n", p1->left->data);
    printf("Right Child = %d\n", p1->right->data);

    // Printing children of node 15
    printf("\nLeft and Right Child of %d:\n", p2->data);
    printf("Left Child = %d\n", p2->left->data);
    printf("Right Child = %d\n", p2->right->data);

    return 0;
}