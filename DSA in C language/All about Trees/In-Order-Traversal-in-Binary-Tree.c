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

    // Allocating memory for node
    n = (struct node *) malloc(sizeof(struct node));

    // Assigning data
    n->data = data;

    // Initially left and right child are NULL
    n->left = NULL;
    n->right = NULL;

    return n;
}

// Inorder Traversal
// Left -> Root -> Right
void inOrder(struct node* root){

    if(root != NULL){

        inOrder(root->left);

        printf("%d ", root->data);

        inOrder(root->right);
    }
}

int main(){

    // Creating nodes
    struct node *p = createNode(4);

    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);

    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    /*
            4
           / \
          1   6
         / \
        5   2
    */

    // Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("Binary Tree Created Successfully\n");

    printf("\nInorder Traversal (Left -> Root -> Right):\n");

    inOrder(p);

    return 0;
}