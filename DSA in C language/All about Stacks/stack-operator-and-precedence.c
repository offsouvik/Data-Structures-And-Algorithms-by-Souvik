#include <stdio.h>

int precedence(char ch){
    if(ch == '*' || ch == '/') return 3;
    else if(ch == '+' || ch == '-') return 2;
    else return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    return 0;
}

int main(){
    printf("Is '+' operator: %d\n", isOperator('+'));
    printf("Precedence of '*': %d\n", precedence('*'));
    printf("Precedence of '+': %d\n", precedence('+'));

    return 0;
}