#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{

    int elemento;
    struct nodo *successivo;

} nodo;

typedef struct list
{
    int elemento;
    struct nodo *head;
    struct list *successivo;
} list;

nodo *aggiungi_in_testa(int n, nodo *testa);
nodo *aggiungi_in_coda(int n, nodo *testa);

list *aggiungi_in_testal(int n, int b, list *testa);
list *aggiungi_in_codal(int n, int b, list *testa);

nodo *aggiungi_in_testa(int n, nodo *testa)
{
    if (testa != NULL)
    {
        nodo *nodoSuccessivo = testa;
        testa = (nodo *)malloc(sizeof(nodo));
        testa->elemento = n;
        testa->successivo = nodoSuccessivo;
    }
    else
    {
        testa = (nodo *)malloc(sizeof(nodo));
        testa->elemento = n;
        testa->successivo = NULL;
    }
    return testa;
}

nodo *aggiungi_in_coda(int n, nodo *testa)
{
    if (testa != NULL)
    {
        nodo *nodoSuccessivo = testa;
        while (nodoSuccessivo->successivo != NULL)
        {
            if (nodoSuccessivo->elemento == n)
                exit(1);
            nodoSuccessivo = nodoSuccessivo->successivo;
        }
        nodoSuccessivo->successivo = aggiungi_in_testa(n, NULL);
    }
    else
    {
        testa = aggiungi_in_testa(n, testa);
    }
    return testa;
}
list *aggiungi_in_testal(int n, int b, list *testa)
{
    if (testa != NULL)
    {
        list *nodoSuccessivo = testa;
        testa = (list *)malloc(sizeof(list));
        testa->elemento = n;
        testa->successivo = nodoSuccessivo;
    }
    else
    {
        testa = (list *)malloc(sizeof(list));
        testa->elemento = n;
        testa->successivo = NULL;
    }
    return testa;
}

list *aggiungi_in_codal(int n, int b, list *testa)
{
    if (testa != NULL)
    {
        list *nodoSuccessivo = testa;
        while (nodoSuccessivo->successivo != NULL)
        {
            if (nodoSuccessivo->elemento == n)
                nodoSuccessivo->head = aggiungi_in_coda(b, nodoSuccessivo->head);

            nodoSuccessivo = nodoSuccessivo->successivo;
        }
        nodoSuccessivo->successivo = aggiungi_in_testal(n, b, NULL);
    }
    else
    {
        testa = aggiungi_in_testal(n, b, testa);
    }
    return testa;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    int a = 1, b = 0, N, M;
    fscanf(input, "%d %d\n", &N, &M);

    list *ciaone = NULL;

    for (unsigned int i = 0; i < M; i++)
    {
        fscanf(input, "%d %d\n", &a, &b);
        ciaone = aggiungi_in_codal(a, b, ciaone);
        ciaone = aggiungi_in_codal(b, a, ciaone);
    }
    return 0;
}