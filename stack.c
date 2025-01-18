#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack createstack(stack s, int size){
    s = (stack) malloc(sizeof(struct __stacknode));
    s->ele = (int *)malloc(size * sizeof(int));
    s->size = size;
    s->top = -1;  // top index
    return s;
}

int isFull(stack s){
    return (s -> top + 1 == s -> size)? 1: 0;
}

int isEmpty(stack s){
    return s -> top == -1;
}

void push(stack s, int value){
    if (isFull(s)){
        // printf("stack is full.\n");
        return;
    }
    s -> top = s -> top + 1;
    s -> ele[s -> top] = value;
}

int pop(stack s){
    if (isEmpty(s)){
        // printf("stack is empty.\n");
        return -1;
    }
    int t = s -> top;
    s -> top = s -> top - 1;
    return s -> ele[t];
}

int peek(stack s){
    if (isEmpty(s)){
        // printf("stack is empty.\n");
        return -1;
    }
    return s -> ele[s -> top];
}
void destroystack(stack s){
    s -> size = 0;
    s -> top = -1;
    free(s -> ele);
    s -> ele = NULL;
}