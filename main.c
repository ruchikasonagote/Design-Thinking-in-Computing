#include <stdio.h>
#include "stack.c"

int main(){
    stack s = createstack(s, 20);
    for(int i = 0; i < 20; i++){
        push(&s, i);
        printf("%d\n", peek(&s));
    }
    int val = pop(&s);
    printf("%d\n", val);
}