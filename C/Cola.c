/*a. Se tiene una cola de números enteros. Implemente un algoritmo en C que
imprima la cantidad de números pares en la cola.
b. Usando operaciones de TAD cola, escriba una función en C para realizar una
copia de una cola en otra.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct Espera {
    Nodo* frente;
    Nodo* trasera;
} Espera;

void enqueue(Espera* espera, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;

    if (espera->trasera == NULL) {
        espera->frente = nuevoNodo;
        espera->trasera = nuevoNodo;
    } else {
        espera->trasera->next = nuevoNodo;
        espera->trasera = nuevoNodo;
    }
}

int contadorNumerosPares(Espera* espera) {
    int contador = 0;
    Nodo* actual = espera->frente;

    while (actual != NULL) {
        if (actual->dato % 2 == 0) {
            contador++;
        }
        actual = actual->next;
    }

    return contador;
}

int main() {
    Espera espera;
    espera.frente = NULL;
    espera.trasera = NULL;

    // Add elements to the espera
    enqueue(&espera, 1);
    enqueue(&espera, 2);
    enqueue(&espera, 3);
    enqueue(&espera, 4);
    enqueue(&espera, 5);

    // Count the number of even numbers
    int contadorPar = contadorNumerosPares(&espera);
    printf("Number of even numbers in the espera: %d\n", contadorPar);

    return 0;
}