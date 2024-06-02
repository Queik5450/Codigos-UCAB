/*
Desarrolle una función que invierta una Pila usando una Cola, basados en
las funciones básicas de cada uno de los TAD. Implemente la función
desarrollada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int element;
    struct node *next;
}Node;

typedef struct stack
{
    Node *head;
}Stack;

typedef struct queue
{
    Node *start;
    Node *end;
}Queue;

Stack *newStack()
{
    Stack *s;
    if ((s=(Stack *)malloc(sizeof(Stack)))==NULL)
    {
        exit(1);
    }
    s->head = NULL;
    return s;
}

Queue * newQueue()
{
    Queue *q;
    if ((q = (Queue*)malloc(sizeof(Queue))) == NULL)
    {
        exit(1);
    }
    q->start = q->end =NULL;
    return q;
}

int top(Stack *s, int *value)
{
    if (s && s->head)
    {
        *value = s->head->element;
        return 1;
    }
    return 0;
}

int push(Stack *s, int value)
{
    Node *newp;
    if (!s)
    {
        return 0;
    }
    if ((newp = (Node *) malloc (sizeof(Node))) == NULL)
    {
        return 0;
    }
    newp->next=s->head;
    newp->element = value;
    s->head=newp;
    return 1;
}

int put_in_queue(Queue *q, int value)
{
    Node *newp;
    if (!q)
    {
        return 0;
    }
    if ((newp = (Node*)malloc(sizeof(Node))) == NULL)
    {
        exit(1);
    }

    newp->next=NULL;
    newp->element = value;

    if (!q->start)
    {
        q->start = q->end = newp;
    }
    else
    {
        q->end->next = newp;
        q->end = newp;
    }
    return 1;
}

int pop(Stack *s, int *value)
{
    if (s && s->head && value)
    {
        Node *aux = s->head;
        s->head =aux->next;
        *value = aux->element;
        free(aux);
        return(1);
    }
    return 0;
}

void add_to_front(Queue *q, int value)
{
    Node *newp;
    if (!q)
    {
        return;
    }
    if ((newp = (Node*)malloc(sizeof(Node))) == NULL)
    {
        exit(1);
    }
    newp->element = value;
    newp->next = q->start;
    q->start = newp;
    if (!q->end)
    {
        q->end = newp;
    }
}

int empty(Stack *s)
{
    if (!s||!s->head)
    {
        return 1;
    }
    return 0;
}

void invertStack(Stack *s, Queue *q) 
{
    int value;

    while (!empty(s)) 
    {
        pop(s, &value);
        add_to_front(q, value);
    }
}

void printStack(Stack *s)
{
    Node *aux = s->head;
    while (aux)
    {
        printf("%d\n", aux->element);
        aux = aux->next;
    }
}

void printQueue(Queue *q)
{
    Node *aux = q->start;
    while (aux)
    {
        printf("%d\n", aux->element);
        aux = aux->next;
    }
}

int main()
{
    Stack *s = newStack();
    Queue *q = newQueue();

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);

    printf("Stack\n");
    printStack(s);
    
    printf("Queue\n");
    invertStack(s, q);
    printQueue(q);

    return 0;

}