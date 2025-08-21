#include "./include/stack.h"

STACK_TYPE array[STACK_SIZE];
int top = -1;

void make_empty(void){
    top = -1;
}

int is_empty(void){
    return (top == -1)? 1 : 0;
}

int is_full(void){
    return (top == (STACK_SIZE-1))? 1: 0;
}

void push(STACK_TYPE i){
    array[++top] = i;
}

STACK_TYPE pop(void){
    return array[top--];
}