#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};  // ✅ fixed

void createArray(struct myarray *a, int tsize, int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myarray *a){
    for(int i = 0; i < a->used_size; i++){
        printf("%d\n", a->ptr[i]);
    }
}

void setval(struct myarray *a){
    int n;
    for(int i = 0; i < a->used_size; i++){
        printf("Enter the value of %d element: ", i);
        scanf("%d", &n);
        a->ptr[i] = n;   // ✅ fixed
    }
}

int main(){
    struct myarray marks;
    createArray(&marks, 100, 2);  
    printf("We are running setval now\n");
    setval(&marks);
    printf("We are running show now\n");
    show(&marks);

    return 0;
}
