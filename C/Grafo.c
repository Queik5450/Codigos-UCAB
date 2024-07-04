/*
Implementar una función en C para leer un grafo dirigido desde un archivo de
texto en formato de lista de adyacencia y almacenarlo en una estructura de
datos adecuada. Considere que cada arista tiene un peso entero y representa
la longitud de un vértice a otro, y cada vértice representa un sitio específico de
la ciudad (por ejemplo: La Llovizna, Plaza Monumental, Muelle Macagua, etc.).
Escriba una función en C para imprimir adecuadamente la estructura creada.

Ejemplo de entrada del archivo de texto:
La Llovizna: Plaza Monumental (10), Muelle Macagua (15)
Plaza Monumental: La Llovizna (10), Catedral (5), Mercado Municipal (7)
Muelle Macagua: La Llovizna (15), Paseo Caroní (8)
Catedral: Plaza Monumental (5), Museo Guayana (12)
Mercado Municipal: Plaza Monumental (7), Plaza Bolívar (9)
Paseo Caroní: Muelle Macagua (8)
Plaza Bolívar: Mercado Municipal (9)
Museo Guayana: Catedral (12)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge 
{
    int destination;
    int weight;
    struct edge* next;
} Edge;

typedef struct Vertex 
{
    int id;
    Edge* head;
} Vertex;

typedef struct Graph 
{
    int numVertices;
    Vertex* vertexList;
} Graph;

Graph* createGraph(int numVertices) 
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertexList = (Vertex*)malloc(numVertices * sizeof(Vertex));

    for (int i = 0; i < numVertices; i++) 
    {
        graph->vertexList[i].id = i;
        graph->vertexList[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int source, int destination, int weight) 
{

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destination = destination;
    newEdge->weight = weight;

    newEdge->next = graph->vertexList[source].head;
    graph->vertexList[source].head = newEdge;

}

char* vertexNames[] = {"La Llovizna", "Plaza Monumental", "Muelle Macagua", "Parque Cachamay", NULL};

int getVertexId(char* vertexName) 
{
    int i = 0;
    while (vertexNames[i] != NULL) 
    {
        if (strcmp(vertexNames[i], vertexName) == 0) 
        {
            return i;
        }
        i++;
    }
    return -1;
}

void readGraphFromFile(Graph* graph, char* fileName) 
{
    FILE* file = fopen(fileName, "r");
    if (!file) 
    {
        perror("Error abriendo archivo");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) 
    {
        char* vertexName = strtok(line, ",");
        if (!vertexName) continue;

        int source = getVertexId(vertexName);
        if(source == -1) continue;

        char* destinationName = strtok(NULL, ",");
        char* weightStr = strtok(NULL, ",");
        if (!destinationName || !weightStr) continue;

        int destination = getVertexId(destinationName);
        if(destination == -1) continue;

        int weight = atoi(weightStr);

        addEdge(graph, source, destination, weight);
    }

    fclose(file);
}

void printGraph(Graph* graph) 
{
    for (int i = 0; i < graph->numVertices; i++) 
    {
        Edge* edge = graph->vertexList[i].head;
        printf("Vertice %d:\n", i);
        while (edge) 
        {
            printf("  -> %d (Peso: %d)\n", edge->destination, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) 
{
    for (int i = 0; i < graph->numVertices; i++) 
    {
        Edge* edge = graph->vertexList[i].head;
        while (edge) 
        {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->vertexList);
    free(graph);
}

int main() 
{
    // Create the graph and read from the file
    Graph* graph = createGraph(8);
    readGraphFromFile(graph, "Sitios.txt"); // Place file in "output" folder
    printGraph(graph);

    freeGraph(graph);

    return 0;
}
