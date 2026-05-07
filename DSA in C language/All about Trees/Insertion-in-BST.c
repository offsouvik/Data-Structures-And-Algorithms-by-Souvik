#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){

    struct node *n;

    // Allocating memory
    n = (struct node *) malloc(sizeof(struct node));

    // Assigning data
    n->data = data;

    // Initially children are NULL
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

// Insertion in BST
void insert(struct node *root, int key){

    struct node *prev = NULL;

    while(root != NULL){

        prev = root;

        // Duplicate value check
        if(key == root->data){

            printf("\n%d already exists in BST\n", key);

            return;
        }

        // Move left
        else if(key < root->data){

            root = root->left;
        }

        // Move right
        else{

            root = root->right;
        }
    }

    // Creating new node
    struct node* new = createNode(key);

    // Linking new node
    if(key < prev->data){

        prev->left = new;
    }

    else{

        prev->right = new;
    }

    printf("\nInserted %d successfully\n", key);
}

int main(){

    // Creating BST
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

    printf("BST Before Insertion:\n");

    inOrder(p);

    printf("\n");

    // Inserting new element
    insert(p, 2);

    printf("\nBST After Insertion:\n");

    inOrder(p);

    printf("\n");

    return 0;
}