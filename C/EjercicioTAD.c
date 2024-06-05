/*
Se desea que usted desarrolle TAD para almacenar dos listas de
elementos, donde cada una de las listas son de tipos de datos
diferentes, con las siguientes premisas:
• La suma de las cantidades de ambos tipos de elementos, es
siempre menor o igual a N.
• Los tipos de datos de los elementos difieren en sus atributos.
• Ambas listas se manejan bajo una política LIFO. 
Se desea que usted:
a.- Diseñe una estructura de datos estática óptima para almacenar
ambos grupos de elementos
b.- Asumiendo los atributos de los elementos del tipos1 son int
campo1 y float campo2 y los de los elementos del tipo2 son char
campo3 y char campo4, construya las funciones del TAD para
insertar y remover elementos tipos1 e insertar y remover
elementos tipos2.

TAD = Type of Abstract Data
LIFO = Last In First Out

Si usa LIFO == Pila
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

typedef struct tad
{
    Node *stack1; 
    Node *stack2; 
}TAD;

void initializeTAD(TAD *tad) 
{
    tad->stack1 = NULL;
    tad->stack2 = NULL;
}

void insertType1(TAD *tad, int campo1, float campo2) 
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = campo1;
    newNode->next = tad->stack1;
    tad->stack1 = newNode;
}

int removeType1(TAD *tad) 
{
    if (tad->stack1 == NULL) 
    {
        printf("Error: Stack1 is empty\n");
        return -1;
    }
    int value = tad->stack1->value;
    Node *temp = tad->stack1;
    tad->stack1 = tad->stack1->next;
    free(temp);
    return value;
}

void insertType2(TAD *tad, char campo3, char campo4) 
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = campo3;
    newNode->next = tad->stack2;
    tad->stack2 = newNode;
}

char removeType2(TAD *tad) 
{
    if (tad->stack2 == NULL) 
    {
        printf("Error: Stack2 is empty\n");
        return '\0';
    }
    char value = tad->stack2->value;
    Node *temp = tad->stack2;
    tad->stack2 = tad->stack2->next;
    free(temp);
    return value;
}