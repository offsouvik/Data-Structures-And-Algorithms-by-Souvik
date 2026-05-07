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

// Iterative Search in BST
struct node* searchIter(struct node* root, int key){

    while(root != NULL){

        // Element found
        if(key == root->data){

            return root;
        }

        // Move to left subtree
        else if(key < root->data){

            printf("Moving Left from %d\n", root->data);

            root = root->left;
        }

        // Move to right subtree
        else{

            printf("Moving Right from %d\n", root->data);

            root = root->right;
        }
    }

    return NULL;
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

    printf("\nInorder Traversal:\n");

    inOrder(p);

    printf("\n");

    // Searching element
    int key = 8;

    printf("\nSearching Element = %d\n\n", key);

    struct node* n = searchIter(p, key);

    if(n != NULL){

        printf("\nElement Found: %d\n", n->data);
    }

    else{

        printf("\nElement Not Found\n");
    }

    return 0;
}