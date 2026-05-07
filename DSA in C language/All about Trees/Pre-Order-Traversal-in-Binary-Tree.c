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

    // Allocating memory
    n = (struct node *) malloc(sizeof(struct node));

    // Assigning value
    n->data = data;

    // Initially left and right child are NULL
    n->left = NULL;
    n->right = NULL;

    return n;
}

// Preorder Traversal
// Root -> Left -> Right
void preOrder(struct node* root){

    if(root != NULL){

        printf("%d ", root->data);

        preOrder(root->left);

        preOrder(root->right);
    }
}

int main(){

    // Creating nodes
    struct node *p = createNode(4);

    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);

    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    struct node *p5 = createNode(7);
    struct node *p6 = createNode(8);

    /*
            4
           / \
          1   6
         / \ / \
        5  2 7  8
    */

    // Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    printf("Binary Tree Created Successfully\n");

    printf("\nRoot Node: %d\n", p->data);

    printf("\nChildren of Node %d:\n", p->data);
    printf("Left Child  = %d\n", p->left->data);
    printf("Right Child = %d\n", p->right->data);

    printf("\nChildren of Node %d:\n", p1->data);
    printf("Left Child  = %d\n", p1->left->data);
    printf("Right Child = %d\n", p1->right->data);

    printf("\nChildren of Node %d:\n", p2->data);
    printf("Left Child  = %d\n", p2->left->data);
    printf("Right Child = %d\n", p2->right->data);

    printf("\nPreorder Traversal (Root -> Left -> Right):\n");

    preOrder(p);

    return 0;
}