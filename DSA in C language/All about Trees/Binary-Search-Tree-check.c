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

// Function to check whether tree is BST or not
int isBST(struct node* root){

    // Static pointer stores previous node
    static struct node *prev = NULL;

    if(root != NULL){

        // Checking left subtree
        if(!isBST(root->left)){
            return 0;
        }

        // BST condition check
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }

        // Updating previous node
        prev = root;

        // Checking right subtree
        return isBST(root->right);
    }

    else{
        return 1;
    }
}

int main(){

    // Creating nodes
    struct node *p = createNode(5);

    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);

    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    /*
            5
           / \
          3   6
         / \
        1   4
    */

    // Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("Binary Tree Created Successfully\n");

    printf("\nInorder Traversal:\n");

    inOrder(p);

    printf("\n");

    // Checking BST condition
    if(isBST(p)){

        printf("\nThis tree is a Binary Search Tree (BST)\n");
    }

    else{

        printf("\nThis tree is NOT a Binary Search Tree (BST)\n");
    }

    return 0;
}