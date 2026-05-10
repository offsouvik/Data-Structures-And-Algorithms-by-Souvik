#include<stdio.h>
#include<stdlib.h>

// Visited Array
int visited[7] = {0,0,0,0,0,0,0};

// Adjacency Matrix
int A[7][7] = {

    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

// To Store Final DFS Traversal
int traversal[7];

int k = 0;

// DFS Function
void DFS(int i){

    printf("\nVisiting Node: %d\n", i);

    visited[i] = 1;

    traversal[k++] = i;

    for(int j = 0; j < 7; j++){

        if(A[i][j] == 1 && !visited[j]){

            printf("Connected Node Found from %d to %d\n", i, j);

            DFS(j);
        }
    }
}

int main(){

    printf("Depth First Search (DFS) Traversal\n");

    printf("\nStarting DFS from Node 0\n");

    // DFS Start
    DFS(0);

    printf("\n\nDFS Traversal Completed\n");

    // Final Traversal Output
    printf("\nFinal DFS Traversal:\n");

    for(int i = 0; i < k; i++){

        printf("%d ", traversal[i]);
    }

    printf("\n");

    return 0;
}