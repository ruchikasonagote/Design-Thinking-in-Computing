# ifndef _STACK_H_
# define _STACK_H_
#include <stdbool.h>
#include <stdio.h>

typedef struct NODE node;
struct NODE {
    int val;
    node *prev, *next;
};

// Although the struct's name is uppercase contrary to convention,
// We need it for an all lowercase type-name.
typedef struct STACK *stack;
struct STACK { 
    int elements;
    int capacity;
    node* head; // not really needed though
    node* top;
};

// Assuming the stack is pre-allocated with capacity.
// And that we always have space for it. Otherwise segfault and panic.
// Should ideally return a Result type equivalent
stack create_stack(int capacity);

void destroy_stack(stack s);

// Is a no-op if the stack is full
// Should ideally return a Result type equivalent
void push(stack s, int value);

// Returns -1 if the stack is empty
// Should ideally return an Option type equivalent
int pop(stack s);

// Returns -1 if the stack is empty
// Should ideally return an Option type equivalent
int top(stack s);

bool is_full(stack s);

bool is_empty(stack s);

# endif //! _STACK_H_
