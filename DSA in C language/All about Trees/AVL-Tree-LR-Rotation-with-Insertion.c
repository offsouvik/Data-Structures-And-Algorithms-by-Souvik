// ================= AVL TREE LR ROTATION =================

#include <stdio.h>
#include <stdlib.h>

struct Node{

    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n){

    if(n == NULL)
        return 0;

    return n->height;
}

struct Node *createNode(int key){

    struct Node* node =
    (struct Node *) malloc(sizeof(struct Node));

    node->key = key;

    node->left = NULL;
    node->right = NULL;

    node->height = 1;

    return node;
}

int max(int a, int b){

    return (a > b) ? a : b;
}

int getBalanceFactor(struct Node *n){

    if(n == NULL){

        return 0;
    }

    return getHeight(n->left)
           - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y){

    struct Node* x = y->left;

    struct Node* T2 = x->right;

    x->right = y;

    y->left = T2;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x){

    struct Node* y = x->right;

    struct Node* T2 = y->left;

    y->left = x;

    x->right = T2;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    return y;
}

struct Node *insert(struct Node* node, int key){

    if(node == NULL)
        return createNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);

    else if(key > node->key)
        node->right = insert(node->right, key);

    else
        return node;

    node->height =
    1 + max(getHeight(node->left),
            getHeight(node->right));

    int bf = getBalanceFactor(node);

    // LR Rotation
    if(bf > 1 && key > node->left->key){

        printf("\nLR Rotation Applied on Node %d\n", node->key);

        node->left = leftRotate(node->left);

        return rightRotate(node);
    }

    return node;
}

void preOrder(struct Node *root){

    if(root != NULL){

        printf("%d ", root->key);

        preOrder(root->left);

        preOrder(root->right);
    }
}

int main(){

    struct Node *root = NULL;

    printf("AVL Tree - LR Rotation Example\n");

    printf("\nInserting Nodes:\n");

    root = insert(root, 50);
    printf("Inserted: 50\n");

    root = insert(root, 30);
    printf("Inserted: 30\n");

    root = insert(root, 40);
    printf("Inserted: 40\n");

    root = insert(root, 20);
    printf("Inserted: 20\n");

    root = insert(root, 35);
    printf("Inserted: 35\n");

    root = insert(root, 45);
    printf("Inserted: 45\n");

    printf("\nPreOrder Traversal After Balancing:\n");

    preOrder(root);

    printf("\n");

    return 0;
}