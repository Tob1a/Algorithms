// algoritmo che lavora inizialmente sulla x e poi sulla y
// algoritmo che esegue la differenza delle delle y
// l'algoritmo utilizza le struct

/*quicksort prof
steps vs l'implementazione di algoritmi di ordinamento (confronti) effincienti in pratica

strategie migliorative per quicksort
\                    /
    Euristiche
                        Il problema di quicksort ha un caso pessimo che ha n^2
                        e ha un caso normale n*log(n)

    scegliere meglio il pivot per la partizione
        |-> mediana di tre
        |-> mediana di cinque
        |-> mediana di ...

        finche' rimangono numeri molto piccoli ci sta
    scegliere perfettamente il pivot
        andare a scegliere la mediana. prima non lo potevo fare perche ha un costo
            posso usare una versione ottima di select = medians of medians

    agire sulla ricorsione
        |->eliminare la prima tail ricorsione
        (Tutte le ricorsione sono inefficienti)
        |->ottimizzare la scelta della chiamata rimanente (sulla parte piu' piccola dell'array)
        |->eliminare la seconda chiamata tail_ricorsiva

    ibridazione
        1 Insertion sort (esempio grafico quicksort insertion sort)
        2 HeapSort
        3 con entrambi

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int finale;
    int iniziale;
} c;
int main(void)
{
    FILE *input = fopen("input.txt", "r");
    int *arr, M, i, area[5];
    fscanf(input, "%d\n", &M);
    arr = (int *)malloc(M * sizeof(int));
    c ciao;
    ciao.finale = 0;
    // cerco max

    // eseguo array aree
    int j = 0;
    // stampo area massima
    for (i = 0; i < M; i++)
    {
        fscanf(input, "%d\n", &ciao.iniziale);
        // for(int j=0;j<i;j++){

        // }
        if (ciao.iniziale > ciao.finale)
        {
            // calcola l'area;
            // diminuisci i rettangoli
            if(area[j] <= area[j-1])
            area[j] += ciao.iniziale;
            ciao.finale = ciao.iniziale;
            ciao.
        }
        else
        {
            j++;
            area[j] += ciao.iniziale;
        }
    }
    int max = 0;
    for (i = 0; i < 5; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    FILE *output = fopen("output.txt", "w");
    fclose(input);
    fprintf(output, "%d", max);
    fclose(output);
    return 0;
}