/*
Implemente en Lenguaje C la definición de la estructura de un TAD árbol
binario de búsqueda, y basado en ello, genere:
a. Una función que imprima en orden las hojas de un árbol.
b. La función int sucesor (nodo_t *A, int *suce) que retorne 1 o 0 en caso
de tener o no sucesor y guarde en suce el valor del nodo sucesor del
árbol dado para imprimirlo posteriormente en main.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int element;
    struct node* left;
    struct node* right;
} Node;

int insert(Node **A, int element)
{
    if (*A == NULL)
    {
        *A = (Node *)malloc(sizeof(Node));
        (*A)->element = element;
        (*A)->left = (*A)->right = NULL;
        return 1;
    }
    if (element == (*A)->element)
    {
        return 0;
    }
    else if (element < (*A)->element)
    {
        return insert(&(*A)->left, element);
    }
    else
    {
        return insert(&(*A)->right, element);
    }
}

int search(Node *A, int element)
{
    if (A == NULL)
    {
        return 0;
    }
    if (element == A->element)
    {
        return 1;
    }
    if (element < A->element)
    {
        return search(A->left, element);
    }
    else
    {
        return search(A->right, element);
    }
}

int sucesor (Node *A, int *suce)
{
    if (A->right != NULL)
    {
        A = A->right;
        while (A->left != NULL)
        {
            A = A->left;
        }
        *suce = A->element;
        return 1;
    }
    else
    {
        Node *parent = NULL;
        Node *current = A;
        while (current != NULL && current->element != *suce)
        {
            if (*suce < current->element)
            {
                parent = current;
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if (current == NULL)
        {
            return 0;
        }
        if (current->right == NULL)
        {
            *suce = parent->element;
            return 1;
        }
        current = current->right;
        while (current->left != NULL)
        {
            current = current->left;
        }
        *suce = current->element;
        return 1;
    }

    return 0;
}

void treeLeaves(Node *A)
{
    if (A == NULL)
        return;

    if (A->left == NULL && A->right == NULL)
    {
        printf("%d ", A->element);
        return;
    }

    treeLeaves(A->left);
    treeLeaves(A->right);
}

void printTree(Node *A, int level)
{
    int i;
    if (A == NULL)
    {
        return;
    }
    printTree(A->right, level + 1);
    for (i = 0; i < level; i++)
    {
        printf(" ");
    }
    printf("%d\n", A->element);
    printTree(A->left, level + 1);
}

int main() 
{
    Node *root = NULL;

    int level=0;

    //Cambiar los valores enteros para cambiar el arbol, tambien se pueden ingresar nuevos valores
    insert(&root,5);
    insert(&root,2);
    insert(&root,3);
    insert(&root,7);
    printTree(root, level);
    printf("\n");

    printf("Hojas del arbol: ");
    treeLeaves(root);
    printf("\n");
    
    int suce;
    int element = 2;

    Node *node = NULL;
    
    if (search(root, element)) 
    {
        node = root;
    }

    if (node != NULL && sucesor(node, &suce)) 
    {
        printf("Sucesor de %d: %d\n", node->element, suce);
    } 
    else 
    {
        printf("El nodo %d no tiene sucesor\n", node ->element);
    }

    return 0;
}
