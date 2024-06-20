/*
La función int predecesor (nodo_t *A, int * pre) que retorne 1 o 0 en caso
de tener o no predecesor y guarde en pre el valor del nodo predecesor
del árbol dado para imprimirlo posteriormente en main.
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

int predecesor (Node *A, int * pre)
{
    if (A->left != NULL)
    {
        A = A->left;
        while (A->right != NULL)
        {
            A = A->right;
        }
        *pre = A->element;
        return 1;
    }
    else
    {
        Node *parent = NULL;
        Node *current = A;
        while (current != NULL && current->element != *pre)
        {
            if (*pre < current->element)
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
            *pre = parent->element;
            return 1;
        }
        current = current->right;
        while (current->left != NULL)
        {
            current = current->left;
        }
        *pre = current->element;
        return 1;
    }
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

void freeTree(Node **A) 
{
    if (*A != NULL) 
    {
        freeTree(&(*A)->left);
        freeTree(&(*A)->right);
        free(*A);
    }
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
    insert(&root,1);
    insert(&root,4);
    printTree(root, level);
    printf("\n");

    int pre;
    int element = 2;

    Node *node = NULL;
    
    if (search(root, element)) 
    {
        node = root;
    }

    if (node != NULL && predecesor(node, &pre)) 
    {
        printf("Predecesor de %d: %d\n", node->element, pre);
    } 
    else 
    {
        printf("El nodo %d no tiene predecesor\n", node ->element);
    }
    freeTree(&root);
    return 0;
}
