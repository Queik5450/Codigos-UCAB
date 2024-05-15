#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 15

typedef struct list
{
    int long;
    int actual;
    int elements[MAX_ELEMENTS];
}List;

typedef struct node
{
    int element;
    struct nodo *next;
}Node;

typedef struct list
{
    Node *start, *finish;

}list_t;

typedef struct node
{
    int element;
    struct node *next, *prev;
}node_t;

typedef struct list
{
    node_t *start, *finish;
}list_t;



