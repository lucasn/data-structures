#include <stdio.h>
#include "stack.h"

int main(void){
    // testing the stack
    Stack *stack = createStack();
    printf("%d\n", isEmptyStack(stack));

    pushStack(stack, 10);
    pushStack(stack, 20);

    printf("%d\n", isEmptyStack(stack));

    printf("%d\n", getTopStack(stack));

    printf("%d\n", popStack(stack));

    printf("%d\n", getTopStack(stack));
    
    freeStack(stack);
    return 0;
}