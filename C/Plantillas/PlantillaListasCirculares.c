#include <stdio.h>
#include <stdlib.h>

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
        return;
    Node *prev = NULL;
    Node *current = head;
    while (current->data != data)
    {
        if (current->next == head)
            return;
        prev = current;
        current = current->next;
    }

    if (current == head)
    {
        if (current->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = current->next;
            free(current);
        }
    }
    else
    {
        prev->next = current->next;
        free(current);
    }
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