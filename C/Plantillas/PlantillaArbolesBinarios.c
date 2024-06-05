#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *left, *right;
} Node;

int search(Node *binaryTree, int element)
{
    if (binaryTree == NULL)
    {
        return 0;
    }
    if (element == binaryTree->element)
    {
        return 1;
    }
    if (element < binaryTree->element)
    {
        return search(binaryTree->left, element);
    }
    else
    {
        return search(binaryTree->right, element);
    }
}

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

int findMin(Node *binaryTree, int *element)
{
    if (binaryTree == NULL)
    {
        return 0;
    }
    while (binaryTree->left != NULL)
    {
        binaryTree = binaryTree->left;
    }
    *element = binaryTree->element;
    return 1;
}

int findMax(Node *binaryTree, int *element)
{
    if (binaryTree == NULL)
    {
        return 0;
    }
    while (binaryTree->right != NULL)
    {
        binaryTree = binaryTree->right;
    }
    *element = binaryTree->element;
    return 1;
}

int countNodes(Node *binaryTree)
{
    if (binaryTree == NULL)
    {
        return 0;
    }
    return countNodes(binaryTree->left) + countNodes(binaryTree->right) + 1;
}

void deleteTree(Node *binaryTree)
{
    if (binaryTree == NULL)
    {
        return;
    }
    deleteTree(binaryTree->left);
    deleteTree(binaryTree->right);
    free(binaryTree);
}

Node *deleteNode(Node *binaryTree, int element)
{
    Node *temp;

    if (binaryTree == NULL)
    {
        return NULL;
    }

    if (element == binaryTree->element)
    {
        if (binaryTree->left == binaryTree->right)
        {
            free(binaryTree);
            return NULL;
        }
        if (binaryTree->left == NULL)
        {
            temp = binaryTree->right;
            free(binaryTree);
            return temp;
        }
        if (binaryTree->right == NULL)
        {
            temp = binaryTree->left;
            free(binaryTree);
            return temp;
        }
        temp = binaryTree->left;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }

        binaryTree->element = temp->element;
        binaryTree->left = deleteNode(binaryTree->left, temp->element);
        return binaryTree;
    }
    if (element < binaryTree->element)
    {
        binaryTree->left = deleteNode(binaryTree->left, element);
    }
    else
    {
        binaryTree->right = deleteNode(binaryTree->right, element);
    }
    return binaryTree;
}

int treeHeight(Node *binaryTree)
{
    int leftHeight = 0, rightHeight = 0;
    if (binaryTree == NULL)
    {
        return 0;
    }
    if (binaryTree->left != NULL)
    {
        leftHeight = 1 + treeHeight(binaryTree->left);
    }
    if (binaryTree->right != NULL)
    {
        rightHeight = 1 + treeHeight(binaryTree->right);
    }
    if (rightHeight > leftHeight)
    {
        return rightHeight;
    }
    return leftHeight;
}

void inorderTraversal(Node *binaryTree)
{
    if (binaryTree == NULL)
    {
        return;
    }
    inorderTraversal(binaryTree->left);
    printf("%d ", binaryTree->element);
    inorderTraversal(binaryTree->right);
}

void preorderTraversal(Node *binaryTree)
{
    if (binaryTree == NULL)
    {
        return;
    }
    printf("%d ", binaryTree->element);
    preorderTraversal(binaryTree->left);
    preorderTraversal(binaryTree->right);
}

void postorderTraversal(Node *binaryTree)
{
    if (binaryTree == NULL)
    {
        return;
    }
    postorderTraversal(binaryTree->left);
    postorderTraversal(binaryTree->right);
    printf("%d ", binaryTree->element);
}

void printTree(Node *binaryTree, int level)
{
    int i;
    if (binaryTree == NULL)
    {
        return;
    }
    printTree(binaryTree->right, level + 1);
    for (i = 0; i < level; i++)
    {
        printf(" ");
    }
    printf("%d\n", binaryTree->element);
    printTree(binaryTree->left, level + 1);
}

int main(void)
{
    Node *binaryTree = NULL;
    int e;

    insert(&binaryTree, 6);
    insert(&binaryTree, 4);
    insert(&binaryTree, 12);
    insert(&binaryTree, 2);
    insert(&binaryTree, 10);
    insert(&binaryTree, 18);
    insert(&binaryTree, 3);
    insert(&binaryTree, 23);
    insert(&binaryTree, 20);

    printTree(binaryTree, 1);

    printf("\nNumber of elements: %d", countNodes(binaryTree));
    printf("\nHeight: %d", treeHeight(binaryTree));
    printf("\nSearch Element 3: %d", search(binaryTree, 3));
    printf("\nSearch Element 9: %d", search(binaryTree, 9));

    if (findMin(binaryTree, &e))
    {
        printf("\nMinimo: %d", e);
    }
    if (findMax(binaryTree, &e))
    {
        printf("\nMaximo: %d", e);
    }
    printf("\nBorrando elemento: 6\n");
    binaryTree = deleteNode(binaryTree, 6);

    printTree(binaryTree, 1);
    
    printf("\nRecorrido Inorden: ");
    inorderTraversal(binaryTree);

    printf("\nRecorrido Preorden: ");
    preorderTraversal(binaryTree);

    printf("\nRecorrido PostOrden: ");
    postorderTraversal(binaryTree);

    deleteTree(binaryTree);
    return 0;
}