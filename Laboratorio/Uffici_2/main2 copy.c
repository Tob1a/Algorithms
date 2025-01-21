#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *input = fopen("input.txt", "r");
    int *arr, M, i;
    fscanf(input, "%d\n", &M);
    arr = (int *)malloc(M * sizeof(int));
    int retx = 0, retf = 0, max = 0, f;
    for (i = 0; i < M; i++)
    {
        fscanf(input, "%d ", &arr[i]);
        if (max < arr[i])
            max = arr[i];
    }
    int rety[max];
    for (i = 0; i < max; i++)
        rety[i] = 0;
    for (i = 0; i < M; i++)
    {

        // se il risultato e' uguale al precedente
        if (retx == arr[i])
        {
            // incremento di 1 rety diversi da 0
            for (f = 0; f < retx; f++)
            {
                rety[f]++;
                if (retf < ((f + 1) * rety[f]) && (f + 1) != rety[f])
                    retf = (f + 1) * rety[f];
            }
        }
        // se il risultato e' maggiore del precedente
        else if (retx < arr[i])
        {
            for (f = 0; f < arr[i]; f++)
            {
                rety[f]++;
                if (retf < ((f + 1) * rety[f]) && (f + 1) != rety[f])
                    retf = (f + 1) * rety[f];
            }
            retx = arr[i];
        }
        // se il risultato e' minore del precedente
        else if (retx > arr[i])
        {
            // eliminazione
            for (f = retx - 1; f >= arr[i]; f--)
            {
                rety[f] = 0;
                if (retf < ((f + 1) * rety[f]) && (f + 1) != rety[f])
                    retf = (f + 1) * rety[f];
            }
            // aggiunta
            for (f = 0; f < arr[i]; f++)
            {
                rety[f]++;
                if (retf < ((f + 1) * rety[f]) && (f + 1) != rety[f])
                    retf = (f + 1) * rety[f];
            }

            retx = arr[i];
        }
    }
    free(arr);
    fclose(input);
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%d", retf);
    fclose(output);
    return 0;
}