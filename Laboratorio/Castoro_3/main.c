#include <stdio.h>
#include <stdlib.h>

// La macchina di touring e' un astrazione di una macchina
// inizio struct
typedef struct nodi
{
    int rappresentante; // rappresentante di un insieme disgiunto
    int rango;
} nodi;
typedef struct archi
{

} archi;

typedef struct caretti
{

} cart;

void castori(FILE *in_file, FILE *out_file)
{
    int N, K, T;
    fscanf(in_file, "%d %d %d\n", &N, &K, &T);

    nodi node[N];
    archi archi[K];
    cart carts[T];
    int risposte[T];
}

int main()
{
    //  qua si esegue l'apertura del file
    FILE *in_file = fopen("input.txt", "r");

    castori(in_file, out_file);
    return 0;
}