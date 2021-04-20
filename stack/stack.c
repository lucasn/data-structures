#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node {
    int value;
    struct node *previous;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Stack *createStack(){
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (stack == NULL) {
        printf("error in 'createStack': not enough memory");
        exit(1);
    }

    stack->top = NULL;
    return stack;
}

bool isEmptyStack(Stack *stack){
    if (stack->top == NULL) return true;
    return false;
}

void pushStack(Stack *stack, int value){
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL){
        printf("error in pushStack: not enough memory\n");
        exit(1);
    }

    node->value = value;
    if (isEmptyStack(stack)){
        node->previous = NULL;
    }
    else {
        node->previous = stack->top;
    }
    stack->top = node;
}

int popStack(Stack *stack){
    if (isEmptyStack(stack)){
        printf("empty stack\n");
        return 0;
    }
    Node *tmp = stack->top;
    int value = tmp->value;
    stack->top = stack->top->previous;
    free(tmp);
    return value;
}

int getTopStack(Stack *stack){
    if (isEmptyStack(stack)) {
        printf("empty stack\n");
        return 0;
    }
    return stack->top->value;
}

void printStack(Stack *stack){
    if (isEmptyStack(stack)){
        printf("empty stack");
    }
    else {
        printf("top->");
        Node *actualNode = stack->top;
        while (actualNode != NULL){
            printf("%d", actualNode->value);
            if (actualNode->previous != NULL) printf("->");
            actualNode = actualNode->previous;
        }
    }
    printf("\n");
}

void freeStack(Stack *stack){
    while (!isEmptyStack(stack)){
        popStack(stack);
    }
    free(stack);
}