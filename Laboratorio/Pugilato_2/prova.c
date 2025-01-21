#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definisco una struttura per rappresentare un nodo nella lista di adiacenza
struct Node
{
    int dest;
    struct Node *next;
};

// Definisco una struttura per rappresentare una lista di adiacenza
struct AdjList
{
    struct Node *head;
};

// Definisco una struttura per rappresentare un grafo
struct Graph
{
    int V;
    struct AdjList *array;
};

// Funzione per creare un nuovo nodo nella lista di adiacenza
struct Node *newAdjListNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Funzione per creare un grafo con V vertici
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // Creo un array di liste di adiacenza. La dimensione dell'array è V
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    // Inizializzo ogni lista di adiacenza come vuota, impostando head a NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Funzione per aggiungere un arco nel grafo non orientato
void addEdge(struct Graph *graph, int src, int dest)
{
    // Aggiungo un arco dalla sorgente alla destinazione. Un nuovo nodo viene aggiunto nella lista di adiacenza della sorgente.
    struct Node *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Poiché il grafo è non orientato, aggiungo anche un arco dalla destinazione alla sorgente
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

bool checkDuplicateEdges(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        bool *visited = (bool *)calloc(graph->V, sizeof(bool));
        struct Node *pCrawl = graph->array[v].head;
        while (pCrawl)
        {
            if (visited[pCrawl->dest])
            {
                free(visited);
                return true; // Duplicato trovato
            }
            visited[pCrawl->dest] = true;
            pCrawl = pCrawl->next;
        }
        free(visited);
    }
    return false; // Nessun duplicato trovato
}

// Funzione principale
int main()
{

    FILE *input = fopen("input.txt", "r");
    int N, M, a, b;
    fscanf(input, "%d %d\n", &N, &M);
    // Creo il grafo

    struct Graph *graph = createGraph(N);

    for (unsigned int i = 0; i < M; i++)
    {
        fscanf(input, "%d %d\n", &a, &b);

        addEdge(graph, a, b);
    }
    fclose(input);
    FILE *output = fopen("output.txt", "w");
    if (checkDuplicateEdges(graph))
        fprintf(output, "TRUE");
    else
        fprintf(output, "FALSE");
    fclose(output);
    return 0;
}
