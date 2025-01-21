#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *input = fopen("input.txt", "r");
    int *arr, M, i;
    fscanf(input, "%d\n", &M);
    arr = (int *)malloc(M * sizeof(int));
    int retx = 100000, retf = 0, arrvec = 0, max = 0, f;
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

        if (arr[i] == 0)
        {
            retx = 100000;
            for (f = 0; f < max; f++)
                rety[f] = 0;
        }
        else
        {
            f = 0;
            // se il risultato e' uguale al precedente
            // se il risultato e' minore del precedente
            // se il risultato e' maggiore del precedente
            if (retx >= arr[i])
            {
                retx = arr[i];
                while (retx > f)
                {
                    rety[f]++;
                    if (retf < (retx * rety[f]) && retx != rety[f])
                        retf = retx * rety[f];
                    f++;
                }
            }
            else
            {
                // if (arr[i] < arr[i - 1])
                // {
                // tutte queste operazioni quando finisco non quando inizio
                f = arr[i] - 1;          // numero di elementi nell'array
                int boh = arr[i] - retx; // numero di elementi da eliminare
                retx = 0;
                while (retx <= f)
                {
                    if (retf < (retx * rety[f]) && retx != rety[f])
                        retf = retx * rety[f];
                    if (arr[i] > f && f != -1)
                    {
                        rety[boh - 1] = 0;
                        boh--; // riduco numero di elementi da eliminare
                    }

                    f--;
                }
                retx = arr[i];
                //  }
                /*else
                {

                    f++;
                    retx = arr[i];
                    while (retx > f)
                    {
                        rety[f]++;
                        if (retf < (retx * rety[f]))
                            retf = retx * rety[f];
                        f++;
                    }
                }*/
            }
        }
    }
    free(arr);
    fclose(input);
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%d", retf);
    fclose(output);
    return 0;
}