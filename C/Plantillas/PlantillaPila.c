#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
}Node;

typedef struct stack
{
    Node *head;
}Stack;

Stack *newStack()
{
    Stack *s;
    if ((s=(Stack *)malloc(sizeof(Stack)))==NULL)
    {
        exit(1);
    s->head = NULL;
    return s;
    }
}

void nullify(Stack *s)
{
     if (!s)
        return;
    for (Node *curp=s->head; curp ;curp=s->head)
    {
        s->head=curp->next;
        free(curp);
    }
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

int empty(Stack *s)
{
    if (!s||!s->head)
    {
        return 1;
    return 0;
    }
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
        newp->next=s->head;
        newp->element = value;
        s->head=newp;
        return (1);
    }
}

int pop(Stack *s, int value)
{
    if (s && s->head)
    {
        Node *aux = s->head;
        s->head =aux->next;
        value = aux->element;
        free(aux);
        return(1);
    }
    return 0;
}

int main()
{
    Stack *s = newStack();
    int x;
    printf("Vacio %d \n", empty(s));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);

    top(s,&x);
    printf("Elemento en el tope: %d\n", x);
    pop(s,&x);
    printf("Elemento removido: %d\n", x);
    top(s,&x);
    printf("Nuevo elemento en el tope: %d\n", x);
    nullify(s);
    printf("Lista vacia: %d\n", empty);
    return 0;
}