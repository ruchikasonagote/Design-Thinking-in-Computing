#ifndef STACK_H
#define STACK_H

// define stack structure
typedef struct __stacknode {
    int *ele;
    int size;
    int top; // top index
} *stack;

// to create stack
stack createstack(stack s, int size);

// other methods
int isFull(stack s);
int isEmpty(stack s);
void push(stack s, int value);
int pop(stack s);
void destroystack(stack s);

#endif