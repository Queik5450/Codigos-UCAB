/*
Dada la siguiente declaración para un nodo de un árbol AVL:
typedef struct AVLnodo 
{
int elemento,altura;
struct AVLnodo *izq,*der;
} *AVLp;

- La función AVLp rotarDerecha (AVLp A) que realice sobre el
nodo “A” una rotación hacia la derecha y devuelva el apuntador a
la nueva raíz.

- La función AVLp rotarIzquierda (AVLp A) que realice sobre el
nodo “A” una rotación hacia la izquierda y devuelva el apuntador
a la nueva raíz.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLnodo 
{
    int elemento;
    int altura;
    struct AVLnodo *izq;
    struct AVLnodo *der;
} *AVLp;

AVLp rotarDerecha (AVLp A)
{
    AVLp B = A->izq;
    A->izq = B->der;
    B->der = A;
    return B;
}

AVLp rotarIzquierda (AVLp A)
{
    AVLp B = A->der;
    A->der = B->izq;
    B->izq = A;
    return B;
}

int height(AVLp A)
{
    if (A == NULL)
    {
        return 0;
    }
    int heightLeft = height(A->izq);
    int heightRight = height(A->der);
    return (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

int balanceFactor(AVLp A)
{
    if (A == NULL)
    {
        return 0;
    }
    return height(A->izq) - height(A->der);
}

AVLp balance(AVLp A, int elemento)
{
    int balanceFactor = height(A->izq) - height(A->der);

    if (balanceFactor > 1 && elemento < A->izq->elemento)
        return rotarDerecha(A);

    if (balanceFactor < -1 && elemento > A->der->elemento)
        return rotarIzquierda(A);

    if (balanceFactor > 1 && elemento > A->izq->elemento)
    {
        A->izq = rotarIzquierda(A->izq);
        return rotarDerecha(A);
    }

    if (balanceFactor < -1 && elemento < A->der->elemento)
    {
        A->der = rotarDerecha(A->der);
        return rotarIzquierda(A);
    }

    return A;
}

int insert(AVLp *A, int elemento)
{
    if ((*A)==NULL)
    {
        *A =(AVLp)malloc(sizeof(AVLp));
        (*A)->elemento = elemento;
        (*A) ->izq = (*A)->der = NULL;
    }
    if (elemento == (*A)->elemento)
    {
        return 0;
    }
    if (elemento < (*A)->elemento)
    {
        insert(&((*A)->izq), elemento);
        *A = balance(*A,elemento);
        return 1;
        
    }
    else
    {
        insert(&((*A)->der),elemento);
        *A = balance(*A,elemento);
        return 1;
    }
    (*A)->altura = height(*A);
}

void printTree(AVLp A, int altura)
{
    int i;
    if (A==NULL)
    {
        return;
    }
    printTree(A->der,altura + 1);
    for (i=0; i<altura; i++)
    {
        printf(" ");
    }
    printf("%d\n", A->elemento);
    printTree(A->izq, altura + 1);
}

void freeTree(AVLp *A) 
{
    if (*A != NULL) 
    {
        freeTree(&(*A)->izq);
        freeTree(&(*A)->der);
        free(*A);
    }
}

int main()
{
    AVLp * newTreeNode = NULL;
    int altura = 0;

    insert(&newTreeNode,10);
    insert(&newTreeNode,20);
    insert(&newTreeNode,5);
    insert(&newTreeNode,8);
    insert(&newTreeNode,9);
    insert(&newTreeNode,4);
    insert(&newTreeNode,1);
    insert(&newTreeNode, 7);


    printf("Arbol AVL:\n");
    printTree(newTreeNode, altura);

    freeTree(newTreeNode);
}