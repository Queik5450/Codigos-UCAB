/*
Dada una lista de enteros doblemente enlazada, escriba e implemente
una función en C, que elimine los consecutivos duplicados. Por ejemplo:
(1,1,1,2,3,3,1,1,4,5,5,5,5) da como resultado (1,2,3,1,4,5)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
} Node;

typedef Node *array;

typedef struct Array
{
    array first;
    array last;
} Array;

void insert_in_start(Array *L, int n)
{
    array aux = malloc(sizeof(Node));
    aux->info = n;
    aux->next = NULL;
    aux->prev = NULL;
    if (L->first != NULL)
    {
        aux->next = L->first;
        L->first->prev = aux;
    }
    if (L->last == NULL)
    {
        L->last = aux;
    }
    L->first = aux;
}

void insert_in_end(Array *L, int n)
{
    array aux = malloc(sizeof(Node));
    aux->info = n;
    aux->next = NULL;
    aux->prev = NULL;
    if (L->last != NULL)
    {
        aux->prev = L->last;
        L->last->next = aux;
    }
    else
    {
        L->first = aux;
    }
    L->last = aux;
}

void show_elements(Node* head) {
    Node* current = head;
    while (current != NULL) 
    {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

void show_reverse(Node* tail) {
    Node* current = tail;
    while (current != NULL) 
    {
        printf("%d ", current->info);
        current = current->prev;
    }
    printf("\n");
}

void remove_consecutive(Array *L)
{
    array current = L->first;
    array next = current->next;
    while (next != NULL)
    {
        if (current->info == next->info)
        {
            array temp = next->next;
            if (temp != NULL)
            {
                temp->prev = current;
            }
            else
            {
                L->last = current;
            }
            free(next);
            current->next = temp;
            next = temp;
        }
        else
        {
            current = next;
            next = next->next;
        }
    }
}


int main()
{
    int option = 99;
    Array NewArray;
    NewArray.first = NULL;
    NewArray.last = NULL;

    while (option)
    {
        printf("1: Agregar numero al final\n");
        printf("2: Agregar numero al inicio\n");
        printf("3: Mostar lista de fin a inicio\n");
        printf("4: Mostrar lista inicio a fin\n");
        printf("0: SALIR\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
            {
                int newNumber;
                printf("Ingrese numeros para agregar al final de la lista(0 para terminar):\n");
                while (scanf("%d", &newNumber) && newNumber != 0)
                {
                    insert_in_end(&NewArray,newNumber);
                    printf("%d se ha agregado con exito al final de la lista.\n", newNumber);
                }
            }
                break;

            case 2:
            {
                int newNumber;
                printf("Ingrese numeros para agregar al principio de la lista(0 para terminar):\n");
                while (scanf("%d", &newNumber) && newNumber != 0)
                {
                    insert_in_start(&NewArray,newNumber);
                    printf("%d se ha agregado con exito al principio de la lista.\n", newNumber);
                }
                break;
            }

            case 3:
            {
                printf("Lista de fin a inicio:\n\n");
                remove_consecutive(&NewArray);
                show_reverse(NewArray.last);
                int i = 0;
                if (i == 0)
                {
                    printf("La lista esta vacia\n\n");
                }
                else
                {
                    printf("# \n\n");
                }
                getchar();
                break;
            }

            case 4:
            {
                printf("Lista de inicio a fin:\n\n");
                remove_consecutive(&NewArray);
                show_elements(NewArray.first);
                int i = 0;
                if (i==0)
                {
                    printf("La lista esta vacia\n\n");
                }
                else
                {
                    printf("# \n\n");
                }
                getchar();
                break;
            }

            case 0:
            {
                printf("\n Saliendo del programa \n");
                break;
            }

            default:
            {
                printf("Opcion invalida, intente de nuevo.\n");
            }
        }
    }

    return 0;
}