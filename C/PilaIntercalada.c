/*
Dadas dos pilas de caracteres, de a lo sumo 50 elementos (capacidad
de las pilas), generar una cola resultante de intercalar los elementos de
ambas. Se pide desarrollar una función que reciba las pilas y retorne la
cola creada.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node * next;
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

Stack * newStack()
{
    Stack *s;
    if ((s=(Stack *)malloc(sizeof(Stack)))==NULL)
    {
       exit(1);
    }
    s->head = NULL;
    return s;
}

int top(Stack *s, int *value)
{
    if (s && s->head && value)
    {
        *value = s->head->num;
        return 1;
    }
    return 0;
}

int empty(Stack *s)
{
    if (!s || !s->head)
    {
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
    if ((newp = (Node *)malloc(sizeof(Node))) == NULL)
    {
        return 0;
    }
    newp->next = s->head;
    newp->num = value;
    s->head = newp;
    return 1;
}

int pop(Stack *s, int *value)
{
    Node *top;
    if (!s || !s->head)
    {
        return 0;
    }
    top = s->head;
    *value = top->num;
    s->head = top->next;
    free(top);
    return 1;
}

int put_in_queue(Queue *q, int value)
{
    Node *newp;
    if (!q)
    {
        return 0;
    }
    if ((newp = (Node *)malloc(sizeof(Node))) == NULL)
    {
        exit(1);
    }

    newp->next = NULL;
    newp->num = value;

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

void print_queue(Queue *q)
{
    Node *curp;
    for (curp = q->start; curp; curp = curp->next)
    {
        printf("%d ", curp->num);
    }
    printf("\n");
}

Queue *interleave_piles(Stack *s1, Stack *s2)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->start = q->end = NULL;

    int x;
    while (!empty(s1) && !empty(s2))
    {
        pop(s1, &x);
        put_in_queue(q, x);
        pop(s2, &x);
        put_in_queue(q, x);
    }

    while (!empty(s1))
    {
        pop(s1, &x);
        put_in_queue(q, x);
    }

    while (!empty(s2))
    {
        pop(s2, &x);
        put_in_queue(q, x);
    }

    return q;
}

int main()
{
    Stack *s1 = newStack();
    Stack *s2 = newStack();

    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s2, 4);
    push(s2, 5);
    push(s2, 6);

    Queue *q = interleave_piles(s1, s2);
    print_queue(q);

    return 0;
}