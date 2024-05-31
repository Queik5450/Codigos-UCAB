#include <stdio.h>
#define MAX_QUEUE 100

typedef struct circularqueue
{
    int elements[MAX_QUEUE];
    int front;
    int rear;
    int size;
} CircularQueue;

void initializeQueue(CircularQueue *queue) 
{
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int isQueueEmpty(CircularQueue *queue) 
{
    return queue->size == 0;
}

int isQueueFull(CircularQueue *queue) 
{
    return queue->size == MAX_QUEUE;
}

void enqueue(CircularQueue *queue, int element) 
{
    if (isQueueFull(queue)) 
    {
        printf("Error: Cola llena\n");
        return;
    }
    queue->elements[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_QUEUE;
    queue->size++;
}

/* If the value of queue->rear + 1 is greater than or equal to MAX_QUEUE, the modulo operator is applied so that the rear index
returns to the beginning of the array (index 0). This allows the queue to behave in a circular manner, reusing the spaces in the
array as elements are dequeued. */

int dequeue(CircularQueue *queue) 
{
    if (isQueueEmpty(queue)) 
    {
        printf("Error: Cola vacia\n");
        return -1;
    }
    int element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE;
    queue->size--;
    return element;
}
/* If the value of queue->front + 1 is greater than or equal to MAX_QUEUE, the modulo operator is applied so that the front index
returns to the beginning of the array (index 0). This allows the queue to behave in a circular manner, reusing the spaces in the
array as new elements are enqueued. */

int frontOfQueue(CircularQueue *queue) 
{
    if (isQueueEmpty(queue)) 
    {
        printf("Error: Cola vacia\n");
        return -1;
    }
    return queue->elements[queue->front];
}

int sumUntilX(CircularQueue *queue, int x) 
{
    int sum = 0;
    int element;
    while (!isQueueEmpty(queue)) 
    {
        element = dequeue(queue);
        if (element == x)
            return sum;
        sum += element;
    }
    return sum;
}

int main() 
{
    CircularQueue queue;
    int i, x;
    initializeQueue(&queue);
    for (i = 1; i <= 5; i++)
        enqueue(&queue, i);
    printf("Cola: ");
    for (i = queue.front; i < queue.front + queue.size; i++)
        printf("%d ", queue.elements[i % MAX_QUEUE]);
    printf("\n");

    printf("Ingresar valor de X: ");
    scanf("%d", &x);

    int sumUntilX = sumUntilX*(&queue, x);
    printf("Sumar hasta X: %d\n", sumUntilX);
    return 0;
}
