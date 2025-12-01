#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct Stack {
    struct Node* top;
} Stack;

// Allocates and initializes an empty stack container.
Stack* createStack();

// Pushes a new element onto the stack; newest node becomes the top.
void push(Stack* stack, void* data);

// Removes and returns the element at the top of the stack; NULL if empty.
void* pop(Stack* stack);

// Returns the data at the top without removing it; NULL when stack is empty.
void* peek(Stack* stack);

// Indicates whether the stack currently holds any items.
int isEmpty(Stack* stack);

// Counts how many nodes are stored in the stack.
int getSize(Stack* stack);

// Iterates from top to bottom, printing each element with the provided callback.
void printStack(Stack* stack, void (*printFunc)(void*));

// Clears all elements, frees the stack object itself, and nulls the caller's ref.
void destroyStack(Stack** stackRef, void (*freeFunc)(void*));
