/*
Implemente en lenguaje C una función que dados dos árboles binarios de
búsqueda verifiquen si son iguales.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int element;
    struct node* left;
    struct node* right;
}Node;

int insert(Node **binaryTree, int element)
{
    if (*binaryTree == NULL)
    {
        *binaryTree = (Node *)malloc(sizeof(Node));
        (*binaryTree)->element = element;
        (*binaryTree)->left = (*binaryTree)->right = NULL;
        return 1;
    }
    if (element == (*binaryTree)->element)
    {
        return 0;
    }
    if (element < (*binaryTree)->element)
    {
        return insert(&((*binaryTree)->left), element);
    }
    else
    {
        return insert(&((*binaryTree)->right), element);
    }
}

bool areEqual(Node* root1, Node* root2) 
{
    if (root1 == NULL && root2 == NULL) 
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL) 
    {
        return false;
    }
    if (root1->element != root2->element) 
    {
        return false;
    }
    return areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

void printTree(Node* binaryTree) 
{
    if (binaryTree == NULL) 
    {
        return;
    }

    printTree(binaryTree->left);
    printf("%d ", binaryTree->element);
    printTree(binaryTree->right);
}

int main()
{
    //CAMBIAR CUALQUIERA DE LOS DATOS EN AMBOS ARBOLES PARA LAS PRUEBAS, AHORA MISMO SON IGUALES.
    //AL CAMBIAR LO QUE SEA NO SEGUIRAN SIENDO IGUALES.
    Node *binaryTree1 = NULL;
    Node *binaryTree2 = NULL;

    insert(&binaryTree1, 1);
    insert(&binaryTree1, 2);
    insert(&binaryTree1, 3);
    insert(&binaryTree1, 4);
    insert(&binaryTree1, 5);
    insert(&binaryTree1, 6);

    insert(&binaryTree2, 1);
    insert(&binaryTree2, 2);
    insert(&binaryTree2, 3);
    insert(&binaryTree2, 4);
    insert(&binaryTree2, 5);
    insert(&binaryTree2, 6);

    printf("ARBOL 1: \n");
    printTree(binaryTree1);

    printf("\nARBOL 2: \n");
    printTree(binaryTree2);

    if (areEqual(binaryTree1, binaryTree2))
    {
        printf("Los arboles son iguales.\n");
    } 
    else 
    {
        printf("Los arboles no son iguales.\n");
    }
}
