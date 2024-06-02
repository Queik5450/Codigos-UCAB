#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int element;
    struct node *next;
}Node;

typedef struct queue
{
    Node *start;
    Node *end;
}Queue;

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

void nullify(Queue *q)
{
    Node *curp;
    if (!q)
    {
        return;
    }
    for (curp = q->start ; curp ; curp = q->end)
    {
        q->start = curp ->next;
        free(curp);
    }
    q->end = NULL;
}

int front(Queue *q, int *value)
{
    if (q && q->start)
    {
        *value = q->start->element;
        return 1;
    }
    return 0;
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

int remove_from_queue(Queue *q, int *value)
{
    if (q && q->start)
    {
        Node * aux = q->start;
        q ->start = aux->next;
        if (q->end == aux)
        {
            q->end = NULL;
        }
        *value = aux->element;
        free(aux);
        return 1;
    }
    return 0;
}

int empty(Queue *q)
{
    if (!q || !q->start)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Queue *q = newQueue();
    int x;
    printf("Vacio %d\n", empty(q));
    put_in_queue(q,1);
    put_in_queue(q,2);
    put_in_queue(q,3);
    put_in_queue(q,4);
    put_in_queue(q,5);

    front(q,&x);
    printf("Elemento al frente: %d\n", x);

    remove_from_queue(q, &x);
    printf("Elemento removido: %d\n", x);

    front(q,&x);
    printf("Elemento al frente: %d\n", x);

    nullify(q);
    printf("Vacio: %d\n", empty(q));

    return 0;
}