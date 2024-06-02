/*Implemente las siguientes funciones en C, recibiendo una pila previamente
inicializada como parámetro:
a. EXCH - Intercambia el elemento en el tope con el inmediatamente anterior.
b. Factorial - que calcule el factorial de un número entero dado, usando la pila
para almacenar los resultados intermedios.*/
#include <stdio.h>
#include <stdlib.h>

#define ESPACIO 100

typedef struct 
{
    int dato[ESPACIO];
    int tope;
} Pila;

void iniciarPila(Pila *pila) 
{
    pila->tope = -1;
}

int revisaVacio(Pila *pila) 
{
    return pila->tope == -1;
}

int revisaLlena(Pila *pila) 
{
    return pila->tope == ESPACIO - 1;
}

void push(Pila *pila, int value) 
{
    if (revisaLlena(pila)) 
    {
        printf("Error: Pila sobrecargada\n");
        exit(1);
    }
    pila->dato[++pila->tope] = value;
}

int pop(Pila *pila) {
    if (revisaVacio(pila)) 
    {
        printf("Error: Pila vacia\n");
        exit(1);
    }
    return pila->dato[pila->tope--];
}

void exch(Pila *pila) {
    if (pila->tope < 1) 
    {
        printf("Error: Sin suficientes elementos en la pila\n");
        return;
    }
    int temp = pila->dato[pila->tope];
    pila->dato[pila->tope] = pila->dato[pila->tope - 1];
    pila->dato[pila->tope - 1] = temp;
}

int factorial(Pila *pila, int n) 
{
    if (n < 0) 
    {
        printf("Error: Input invalido\n");
        exit(1);
    }
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    push(pila, n);
    int resultado = 1;
    while (!revisaVacio(pila)) 
    {
        int num = pop(pila);
        resultado *= num;
        if (num > 1) 
        {
            push(pila, num - 1);
        }
    }
    return resultado;
}

int main() 
{
    Pila pila;
    iniciarPila(&pila);

    // Ejemplo de uso de las funciones
    push(&pila, 5);
    push(&pila, 10);
    exch(&pila);
    printf("Arriba: %d\n", pila.dato[pila.tope]); // Debería imprimir 5

    int resultadoFactorial = factorial(&pila, 5);
    printf("Factorial: %d\n", resultadoFactorial); // Debería imprimir 120

    return 0;
}