#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int representative;
    int size;
};

struct Edge
{
    int from;
    int to;
    int weight;
};

void sfortuna(FILE *in_file, FILE *out_file)
{
    int N, M;
    fscanf(in_file, "%d %d\n", &N, &M);
    struct Node nodes[N];
    struct Edge edges[M];
    int u, v, w;
    for (unsigned int i = 0; i < M; i++)
    {
        // u =nodo 1 v=nodo 2 e w=peso arco
        fscanf(in_file, "%d %d %d\n", &edges[i].from, &edges[i].to, &edges[i].weight);
        qsort
    }
}

int main(void)
{
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");

    if (in_file == NULL || out_file == NULL)
    {
        perror("io fopen");
        return -1;
    }

    sfortuna(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0)
    {
        perror("io fclose");
        return -2;
    }

    return 0;
}