#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quicksort.c"

// merge

void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1, n2 = end - mid, i, j, left[n1], right[n2], k;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[start + 1];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    i = j = 0;
    for (k = start; k <= end; k++)
    {
        if (i < n1)
        {
            if (i < n2)
            {
                arr[k] = (left[i] <= right[j]) ? left[i++] : right[j++];
            }
            else
                arr[k] = left[i++];
        }
        else
            arr[k] = right[j++];
    }
}

void merge_Sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_Sort(arr, start, mid);
        merge_Sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

typedef struct nodo
{
    int x, y, z;
    struct nodo *successivo;
} nodo;

void stampa2(nodo *lista, int u, int *i)
{
    if ((*lista).x >= u)
        (*i)++;
    else
    {
        if ((*lista).y >= u)
            (*i)++;
        else
        {
            if ((*lista).z >= u)
                (*i)++;
            else
            {
                if (sqrt(pow((*lista).x, 2) + pow((*lista).y, 2) + pow((*lista).z, 2)) <= u)
                    (*i)++;
            }
        }
    }
}

int stampa(nodo *lista, int u)
{
    double distanza;
    int i = 0;
    while (lista != NULL)
    {
        // sto lavorando qui
        stampa2(lista, u, &i);
        lista = lista->successivo;
    }
    return i;
}

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

    fscanf(input, "%d %d\n", &N, &Q);
    // easter egg: ciao informatico, w gli ingegneri XD
    nodo *inizio, *lista = NULL;
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d %d %d\n", &xyz[0], &xyz[1], &xyz[2]);
        merge_Sort(xyz, 0, 2);
        // QuickSort(xyz, 0, 2);
        lista = aggiungi_in_testa(xyz[0], xyz[1], xyz[2], lista);
    }
    inizio = lista;
    int u[Q];
    // inizio riordinamento

    for (i = Q; i > 0; i--) // ho dovuto fare il ciclo al contrario senno' mi dava i risultati al oirartnoc
    {
        fscanf(input, "%d\n", &u[i]);

        xyz[0] = stampa(lista, u[i]);

        fprintf(output, "%d\n", xyz[0]);
        lista = inizio;
    }

    fclose(input);
    fclose(output);
    return 0;
}