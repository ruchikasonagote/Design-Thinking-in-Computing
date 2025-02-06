#include "stack.h"
#include <stdio.h>

int capacity = 20;

int main() {
    stack s = create_stack(capacity);
    
    for(int i = 0; i < capacity; i++) {
        push(s, i);
    }

    push(s, 20);
    printf("Push is no-op now.\n");

    while(!is_empty(s)) {
        printf("%d\n", pop(s));
    }

    return 0;
}
