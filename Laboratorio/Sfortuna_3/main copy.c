#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000000

typedef struct
{
    int *edges;
    int edge_count;
} Node;

Node graph[MAXN];
int color[MAXN];

bool bfs(int start, int n)
{
    int queue[MAXN], front = 0, back = 0;
    queue[back++] = start;
    color[start] = 0; // start with color 0

    while (front < back)
    {
        int u = queue[front++];
        for (int i = 0; i < graph[u].edge_count; i++)
        {
            int v = graph[u].edges[i];
            if (color[v] == -1)
            {
                color[v] = 1 - color[u]; // alternate color
                queue[back++] = v;
            }
            else if (color[v] == color[u])
            {
                return false; // found same color neighbor
            }
        }
    }
    return true;
}

bool isBipartite(int n)
{
    for (int i = 0; i < n; i++)
    {
        color[i] = -1; // uncolored
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, n))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output)
    {
        perror("Error opening file");
        return 1;
    }

    int N, M;
    fscanf(input, "%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        graph[i].edges = NULL;
        graph[i].edge_count = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        fscanf(input, "%d %d", &u, &v);
        graph[u].edge_count++;
        graph[v].edge_count++;
        graph[u].edges = realloc(graph[u].edges, graph[u].edge_count * sizeof(int));
        graph[v].edges = realloc(graph[v].edges, graph[v].edge_count * sizeof(int));
        graph[u].edges[graph[u].edge_count - 1] = v;
        graph[v].edges[graph[v].edge_count - 1] = u;
    }

    bool result = isBipartite(N);

    fprintf(output, result ? "TRUE\n" : "FALSE\n");

    for (int i = 0; i < N; i++)
    {
        free(graph[i].edges);
    }

    fclose(input);
    fclose(output);

    return 0;
}
