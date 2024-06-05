/*
Modifique la implementación del TAD pila del tal forma que cuando se 
llene la pila, se amplie el tamaño del arreglo al doble de la capacidad 
actual. 
*/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* array;
    int capacity;
    int size;
} Stack;

void init(Stack* stack) {
    stack->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->capacity = INITIAL_CAPACITY;
    stack->size = 0;
}

void push(Stack* stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
    }
    stack->array[stack->size++] = value;
}

int main() {
    Stack stack;
    init(&stack);

    for (int i = 0; i < 20; i++) {
        push(&stack, i);
    }

    for (int i = 0; i < stack.size; i++) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");

    free(stack.array);
    return 0;
}