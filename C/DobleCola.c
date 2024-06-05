/*
Para ir a ver la película "El Salto de los Ángeles" hay dos filas de personas. 
Existe un encargado de dejar entrar a las personas, siguiendo 
instrucciones simples: "Dejar entrar siempre a la persona que es mayor; si
tienen la misma edad, la fila 1 tendrá preferencia”. Desarrolle un 
programa que permita resolver el problema.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void mergeLists(Node **list1, Node **list2)
{
    if (*list1 == NULL)
    {
        *list1 = *list2;
    }
    else if (*list2 != NULL)
    {
        Node *current1 = *list1;
        Node *current2 = *list2;
        Node *temp;

        while (current1 != NULL && current2 != NULL)
        {
            if (current1->value > current2->value)
            {
                temp = current2->next;
                if (current1->next != NULL)
                {
                    current1->next->prev = current2;
                }
                current2->next = current1->next;
                current2->prev = current1;
                current1->next = current2;
                current1 = current2->next;
                current2 = temp;
            }
            else
            {
                current1 = current1->next;
            }
        }

        if (current1 == NULL && current2 != NULL)
        {
            current1 = *list1;
            while (current1->next != NULL)
            {
                current1 = current1->next;
            }
            current1->next = current2;
            current2->prev = current1;
        }
    }
    free(*list2);
    *list2 = NULL;
}

int main()
{
    Node *fila1 = NULL;
    Node *fila2 = NULL;

    // Insert elements into fila1
    insertNode(&fila1, createNode(25));
    insertNode(&fila1, createNode(30));
    insertNode(&fila1, createNode(20));
    insertNode(&fila1, createNode(35));

    // Insert elements into fila2
    insertNode(&fila2, createNode(22));
    insertNode(&fila2, createNode(28));
    insertNode(&fila2, createNode(30));
    insertNode(&fila2, createNode(32));

    printf("Fila 1: ");
    printList(fila1);

    printf("Fila 2: ");
    printList(fila2);

    mergeLists(&fila1, &fila2);

    printf("Fila  despues de la fusion: ");
    printList(fila1);

    return 0;
}