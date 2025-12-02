#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct Stack {
    struct Node* top;
    int size;
} Stack;

// Allocates and initializes an empty stack container.
Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Pushes a new element onto the stack; newest node becomes the top.
void push(Stack* stack, void* data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    node->next = stack->top;

    stack->top = node;

    stack->size++;
}

// Removes and returns the element at the top of the stack; NULL if empty.
void* pop(Stack* stack){

    if(!stack->top){
        return NULL;
    }

    // kesin 1 eleman var artik

    Node* temp = stack->top;

    stack->top = stack->top->next;

    void* userData = temp->data;

    free(temp);

    stack->size--;

    return userData;

}

// Returns the data at the top without removing it; NULL when stack is empty.
void* peek(Stack* stack){
    return stack->top;
}

// Indicates whether the stack currently holds any items.
int isEmpty(Stack* stack){
    return stack->top ? 0 : 1;
}

// Counts how many nodes are stored in the stack.
// O(N) -> O(1)
int getSize(Stack* stack){
    return stack->size;
}

// Iterates from top to bottom, printing each element with the provided callback.
void printStack(Stack* stack, void (*printFunc)(void*)){
    for(Node* temp = stack->top ; temp ; temp = temp->next){
        printFunc(temp->data);
    }
}

// Clears all elements, frees the stack object itself, and nulls the caller's ref.
void destroyStack(Stack* stack, void (*freeFunc)(void*)){
    Node* current = stack->top;

    while(current){
        Node* next = current->next;
        freeFunc(current->data);
        free(current);
        current = next;
    }
}
