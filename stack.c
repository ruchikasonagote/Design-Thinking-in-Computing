#include "stack.h"
#include <stdlib.h>

#define BLANK_VAL -1

node* create_blank_node() {
    node *blank = (node *) malloc(sizeof(node));
    blank->val = BLANK_VAL;
    blank->next = NULL;
    blank->prev = NULL;
    return blank;
}

void pre_allocate_stack(stack s, int capacity) {
    // This node will signify the bottom of the stack
    s->head = create_blank_node(); 
    node* current = s->head;
    for(int i = 0; i < capacity; i++) {
        node* blank = create_blank_node();
        current->next = blank;
        blank->prev = current;
        current = current->next;
    }
    s->top = s->head;
}

stack create_stack(int capacity) {
    stack s = (stack) malloc(sizeof(struct STACK));    
    s->capacity = capacity;
    s->elements = 0;
    s->top = NULL;
    s->head = NULL;
    
    if (capacity <= 0) {
        return s;
    }

    pre_allocate_stack(s, capacity);

    return s;
}

void destroy_stack(stack s) {
    while(s->head != NULL) {
        node* next = s->head->next;
        free(s->head);
        s->head = next;
    }
    free(s);
}

void push(stack s, int value) {
    if (is_full(s)) {
        return;
    }

    s->top = s->top->next;
    s->top->val = value;
    s->elements += 1;
}

int pop(stack s) {
    if (is_empty(s)) {
        return BLANK_VAL;
    }

    int res = s->top->val; // we don't need to reset the value
    s->top = s->top->prev;
    s->elements -= 1;

    return res;
}

int top(stack s) {
    if (is_empty(s)) {
        return BLANK_VAL;
    }

    return s->top->val;
}

bool is_full(stack s) {
    return s->elements == s->capacity;
}

bool is_empty(stack s) {
    return s->elements == 0;
}
