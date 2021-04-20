#ifndef STACK
#define STACK

// defining the boolean data type
typedef enum bool {
    false,
    true
} bool;

// defining the stack structure
typedef struct stack Stack;

// creates a stack and returns a pointer to it
Stack *createStack();

// returns true if the stack if empty and false otherwise
bool isEmptyStack(Stack *stack);

// adds a value to the top of the stack
void pushStack(Stack *stack, int value);

// removes a value from the top of the stack and free it's space
int popStack(Stack *stack);

// return the value in the top of the stack
int getTopStack(Stack *stack);

// prints the stack from top to bottom
void printStack(Stack *stack);

/// remove all the values of the stack and free it's space
void freeStack(Stack *stack);

#endif