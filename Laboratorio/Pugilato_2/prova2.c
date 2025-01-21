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

// Funzione per stampare il grafo
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct Node *pCrawl = graph->array[v].head;
        printf("\n Lista di adiacenza del vertice %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Funzione per controllare se ci sono vertici duplicati nella lista di adiacenza
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
    // Creo il grafo
    int V = 5;
    struct Graph *graph = createGraph(V);

    // Aggiungo gli archi
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Aggiungo un duplicato per testare la funzione
    // addEdge(graph, 2, 1); // Duplicato

    // Stampo il grafo
    printGraph(graph);

    // Controllo se ci sono duplicati
    if (checkDuplicateEdges(graph))
    {
        printf("\nCi sono vertici duplicati nella lista di adiacenza.\n");
    }
    else
    {
        printf("\nNon ci sono vertici duplicati nella lista di adiacenza.\n");
    }

    return 0;
}
