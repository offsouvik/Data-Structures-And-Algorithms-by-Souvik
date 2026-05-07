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

// Function to search element in BST
struct node* search(struct node* root, int key){

    // If root becomes NULL
    if(root == NULL){

        return NULL;
    }

    // If key is found
    if(key == root->data){

        return root;
    }

    // Search in left subtree
    else if(key < root->data){

        return search(root->left, key);
    }

    // Search in right subtree
    else{

        return search(root->right, key);
    }
}

int main(){

    // Creating nodes
    struct node *p = createNode(5);

    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);

    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    struct node *p5 = createNode(7);
    struct node *p6 = createNode(8);

    /*
            5
           / \
          3   6
         / \   \
        1   4   7
                     \
                      8
    */

    // Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p5;

    p5->right = p6;

    printf("Binary Search Tree Created\n");

    printf("\nInorder Traversal of BST:\n");

    inOrder(p);

    printf("\n");

    // Searching element
    int key = 5;

    printf("\nSearching Element = %d\n", key);

    struct node* n = search(p, key);

    if(n != NULL){

        printf("Element Found: %d\n", n->data);
    }

    else{

        printf("Element Not Found\n");
    }

    return 0;
}