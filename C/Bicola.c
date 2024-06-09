/*
La estructura bicola o cola de doble entrada, es una extensión del TAD
cola, al que se le puede añadir a quitar elementos por cualquier extremo.
Los extremos de la bicola se pueden identificar con frente y fin (al igual
que la cola) y sus operaciones básicas son:
a. CrearBicola, inicializa una bicola sin elementos
b. BicolaVacia, retorna true si la bicola es vacia
c. Ponerfrente, añade un elemento al frente
d. PonerFinal, añade un elemento al final
e. QuitarFrente, retira y retorna el elemento de frente de la bicola
f. QuitarFinal, retira y retorna el elemento del final de la bicola
g. Frente, retorna el elemento del extremo frente de la bicola
h. Final, retorna el elemento al extremo final de la bicola
Implemente el TAD bicola usando arreglos circulares.
*/

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct 
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Bicola;

void CrearBicola(Bicola *bicola) 
{
    bicola->front = -1;
    bicola->rear = -1;
}

bool BicolaVacia(Bicola bicola) 
{
    return bicola.front == -1;
}

bool BicolaLlena(Bicola bicola) 
{
    return (bicola.rear + 1) % MAX_SIZE == bicola.front;
}

void PonerFrente(Bicola *bicola, int elemento) 
{
    if (BicolaLlena(*bicola)) 
    {
        printf("Error: Bicola llena\n");
        return;
    }
    if (bicola->front == -1) 
    {
        bicola->front = 0;
        bicola->rear = 0;
    } 
    else 
    {
        bicola->front = (bicola->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    bicola->data[bicola->front] = elemento;
}

void PonerFinal(Bicola *bicola, int elemento) 
{
    if (BicolaLlena(*bicola)) 
    {
        printf("Error: Bicola llena\n");
        return;
    }
    if (bicola->front == -1) 
    {
        bicola->front = 0;
        bicola->rear = 0;
    } 
    else 
    {
        bicola->rear = (bicola->rear + 1) % MAX_SIZE;
    }
    bicola->data[bicola->rear] = elemento;
}

int QuitarFrente(Bicola *bicola) 
{
    if (BicolaVacia(*bicola)) 
    {
        printf("Error: Bicola vacia\n");
        return -1;
    }
    int elemento = bicola->data[bicola->front];
    if (bicola->front == bicola->rear) 
    {
        bicola->front = -1;
        bicola->rear = -1;
    } 
    else 
    {
        bicola->front = (bicola->front + 1) % MAX_SIZE;
    }
    return elemento;
}

int QuitarFinal(Bicola *bicola) 
{
    if (BicolaVacia(*bicola)) 
    {
        printf("Error: Bicola vacia\n");
        return -1;
    }
    int elemento = bicola->data[bicola->rear];
    if (bicola->front == bicola->rear) 
    {
        bicola->front = -1;
        bicola->rear = -1;
    } 
    else 
    {
        bicola->rear = (bicola->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return elemento;
}

int Frente(Bicola bicola) 
{
    if (BicolaVacia(bicola)) 
    {
        printf("Error: Bicola vacia\n");
        return -1;
    }
    return bicola.data[bicola.front];
}

int Final(Bicola bicola) 
{
    if (BicolaVacia(bicola)) 
    {
        printf("Error: Bicola vacia\n");
        return -1;
    }
    return bicola.data[bicola.rear];
}