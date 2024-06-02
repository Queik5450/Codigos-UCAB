/*
Dada una lista simplemente enlazada con un apuntador a su primer
elemento, escriba los algoritmos en C, para:
a. Voltear (invertir) la lista de forma recursiva.
b. Voltear (invertir) la lista de forma iterativa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[20];
    int value;
    struct node *next;

}Node;

Node *new_item(char *name, int value)
{
    Node *newp;

    if ((newp=(Node *)malloc(sizeof(Node)))==NULL)
    {
        fprintf(stderr, "Error en la lista, no se encontro el elemento");
        exit(1);
    }
    strcpy (newp->name,name);
    newp->value = value;
    newp->next = NULL;
    return newp;
}

Node* reverseRecursive(Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }

    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

Node* reverseIterative(Node* head) 
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void freenodes(Node *head, Node *current)
{
    current = head;
    while (current != NULL) 
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    } 
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    head = new_item("Nodo 1", 1);
    tail = head;

    tail->next = new_item("Nodo 2", 2);
    tail = tail->next;

    tail->next = new_item("Nodo 3", 3);
    tail = tail->next;

    //FORMA RECURSIVA
    head = reverseRecursive(head);

    //FORMA ITERATIVA
    //head = reverseIterative(head);

    Node* current = head;
    while (current != NULL) 
    {
        printf("%s: %d\n", current->name, current->value);
        current = current->next;
    }

    freenodes(head, current);
    return 0;
}