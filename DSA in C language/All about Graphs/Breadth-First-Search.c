#include<stdio.h>
#include<stdlib.h>

struct queue{

    int size;
    int f;
    int r;

    int* arr;
};

// Check Queue Empty
int isEmpty(struct queue *q){

    if(q->r == q->f){

        return 1;
    }

    return 0;
}

// Check Queue Full
int isFull(struct queue *q){

    if(q->r == q->size - 1){

        return 1;
    }

    return 0;
}

// Enqueue Operation
void enqueue(struct queue *q, int val){

    if(isFull(q)){

        printf("\nQueue is Full\n");
    }

    else{

        q->r++;

        q->arr[q->r] = val;

        printf("Enqueued Node: %d\n", val);
    }
}

// Dequeue Operation
int dequeue(struct queue *q){

    int a = -1;

    if(isEmpty(q)){

        printf("\nQueue is Empty\n");
    }

    else{

        q->f++;

        a = q->arr[q->f];
    }

    return a;
}

int main(){

    // Queue Initialization
    struct queue q;

    q.size = 400;

    q.f = q.r = 0;

    q.arr = (int*) malloc(q.size * sizeof(int));

    // BFS Variables
    int node;

    int i = 0;

    int visited[7] = {0,0,0,0,0,0,0};

    // To Store Final Traversal
    int traversal[7];

    int k = 0;

    // Adjacency Matrix
    int a[7][7] = {

        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("Breadth First Search (BFS) Traversal\n");

    printf("\nStarting Node: %d\n", i);

    // Mark Starting Node Visited
    visited[i] = 1;

    traversal[k++] = i;

    printf("\nVisited Node: %d\n", i);

    // Enqueue Starting Node
    enqueue(&q, i);

    // BFS Traversal
    while(!isEmpty(&q)){

        node = dequeue(&q);

        printf("\nDequeued Node: %d\n", node);

        for(int j = 0; j < 7; j++){

            if(a[node][j] == 1 && visited[j] == 0){

                printf("Connected Node Found: %d\n", j);

                visited[j] = 1;

                traversal[k++] = j;

                printf("Visited Node: %d\n", j);

                enqueue(&q, j);
            }
        }
    }

    printf("\nBFS Traversal Completed\n");

    // Final Traversal Print
    printf("\nFinal BFS Traversal:\n");

    for(int x = 0; x < k; x++){

        printf("%d ", traversal[x]);
    }

    printf("\n");

    return 0;
}