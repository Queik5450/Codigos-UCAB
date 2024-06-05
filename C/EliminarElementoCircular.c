/*
Implemente la función eliminarElemento que elimine un elemento 
específico de una lista circular. La función debe recibir como parámetros 
la lista y el dato a eliminar, y liberar la memoria del nodo eliminado. El 
programa debe mostrar en pantalla el dato eliminado tras llamar a la 
función.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;

void insertNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(int data)
{
    if (head == NULL)
    {
        printf("Lista vacia.\n");
        return;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current->data != data)
    {
        if (current->next == head)
        {
            printf("Nodo no encontrado.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current == head)
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    }
    else
    {
        prev->next = current->next;
    }
    printf("Dato eliminado: %d\n", current->data);
    free(current);
}

void searchNode(int data)
{
    if (head == NULL)
    {
        printf("Lista vacia.\n");
        return;
    }
    Node *current = head;
    while (current->data != data)
    {
        if (current->next == head)
        {
            printf("Nodo no encontrado.\n");
            return;
        }
        current = current->next;
    }
    printf("El nodo con los datos %d esta en la lista.\n", data);
}

void traverseList()
{
    if (head == NULL)
    {
        printf("Lista vacia.\n");
        return;
    }
    Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
}

int main()
{
    insertNode(10);
    insertNode(20);
    insertNode(30);
    traverseList();
    deleteNode(20);
    traverseList();
    searchNode(40);

    return 0;
}