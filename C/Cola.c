/*a. Se tiene una cola de números enteros. Implemente un algoritmo en C que
imprima la cantidad de números pares en la cola.
b. Usando operaciones de TAD cola, escriba una función en C para realizar una
copia de una cola en otra.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int countEvenNumbers(Queue* queue) {
    int count = 0;
    Node* current = queue->front;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    int evenCount = countEvenNumbers(&queue);
    printf("Numeros pares en espera: %d\n", evenCount);

    return 0;
}