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

    if ((newp=(Node *) malloc (sizeof(Node)))== NULL)
    {
        fprintf(stderr, "Error en la lista, no se encontro el espacio\n");
        exit(1);
    }

    strcpy(newp->name,name);
    newp->value = value;
    newp->next = NULL;
    return newp;
}

Node *remove_item(char *name, Node *listp)
{
    Node *p, *prev=NULL;
    for (p=listp; p!=NULL ;p=p->next)
    {
        if (strcmp(p->name,name) == 0)
        {
            if (p != NULL)
            {
                listp = p->next;
            }
            else
            {
                prev->next = p->next;
            free(p);
            return listp;
            }
        }
        prev=p;
    }
    return listp;
}

Node *addfront(Node *listp, Node *newp)
{
    newp->next=listp;
    return newp;
}

Node *addend(Node *listp, Node *newp)
{
    Node *p;

    if (listp == NULL)
    {
        return newp;
    for (p=listp;listp!=NULL;p=p->next)
    {
        p->next = newp;
    }
    return listp;
    }
}

Node *insert(Node *listp, Node *newp)
{
    Node *p, *prev=NULL;
    for (p=listp; p!=NULL && strcmp(p->name , newp->name)<0 ;p=p->next)
    {
        prev=p;
    }
    p=newp->next;
    if (prev == NULL) //Es en el inicio
    { 
        return newp;
    }
    prev->next=newp;
    return listp;
}

Node *lookup(char *name, Node *listp){
    for (;listp!=NULL; listp=listp->next)
    {
        if (strcmp(name,listp->name) == 0)
        {
            return listp;
        }
        return NULL;
    }
}

int counter(Node *listp)
{
    int n=0;
    
    for (;listp!=NULL; listp=listp->next)
    {
        n++;
    }
    return n;
}

Node *freeall(Node *listp)
{
    for (;listp != NULL ;listp = listp->next)
    {
        free(listp);
    }

}

void print(Node *listp)
{
    printf("||");
    for (;listp !=NULL;listp = listp ->next)
    {
        printf("%s:%d |", listp -> name, listp ->value);
    }
    if (listp != NULL) 
    {
        print(listp);
    }
}

int is_empty(Node *listp)
{
    return listp == NULL;
}