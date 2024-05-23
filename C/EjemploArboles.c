#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
struct NodoArbol {
    int dato;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
};

// Función para crear un nuevo nodo del árbol
struct NodoArbol* crearNodo(int dato) {
    struct NodoArbol* nodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

// Función para insertar un nuevo nodo en el árbol
struct NodoArbol* insertar(struct NodoArbol* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    } else if (dato > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    return raiz;
}

// Función para imprimir el árbol en orden
void imprimirPostOrden(struct NodoArbol* raiz) {
    if (raiz != NULL) {
        imprimirPostOrden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        imprimirPostOrden(raiz->derecho);
    }
}

// Función principal
int main() {
    struct NodoArbol* raiz = NULL;

    // Insertar nodos en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    // Imprimir el árbol en orden
    printf("Árbol en orden: ");
    imprimirPostOrden(raiz);

    return 0;
}