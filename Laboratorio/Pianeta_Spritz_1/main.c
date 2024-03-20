#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo
{
    int x, y, z;
    struct nodo *successivo;
} nodo;

// metodi
nodo *aggiungi_in_testa(int x, int y, int z, nodo *testa);

nodo *aggiungi_in_testa(int x, int y, int z, nodo *testa)
{
    if (testa != NULL)
    {
        nodo *nodoSuccessivo = testa;
        testa = (nodo *)malloc(sizeof(nodo));
        testa->x = x;
        testa->y = y;
        testa->z = z;
        testa->successivo = nodoSuccessivo;
    }
    else
    {
        testa = (nodo *)malloc(sizeof(nodo));
        testa->x = x;
        testa->y = y;
        testa->z = z;
        testa->successivo = NULL;
    }
    return testa;
}

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int N, Q, i, xyz[3];
    double distanza;

    fscanf(input, "%d %d\n", &N, &Q);

    nodo *inizio, *lista = NULL;
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d %d %d\n", &xyz[0], &xyz[1], &xyz[2]);
        lista = aggiungi_in_testa(xyz[0], xyz[1], xyz[2], lista);
    }
    inizio = lista;
    int u[Q];
    for (i = Q; i > 0; i--) // ho dovuto fare il ciclo al contrario senno' mi dava i risultati al oirartnoc
    {
        fscanf(input, "%d\n", &u[i]);

        xyz[0] = 0;

        while (lista != NULL)
        {
            distanza = sqrt(pow((*lista).x, 2) + pow((*lista).y, 2) + pow((*lista).z, 2));
            lista = lista->successivo;
            if (distanza - u[i] <= 0)
                xyz[0]++;
        }

        fprintf(output, "%d\n", xyz[0]);
        lista = inizio;
    }

    fclose(input);
    fclose(output);
    return 0;
}