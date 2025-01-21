#include <stdio.h>
#include <math.h>

// metodi

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int N, Q, i;
    double distanza;

    fscanf(input, "%d %d\n", &N, &Q);

    // vincoli
    if (N < 1 || Q > 100000)
    {
        fprintf(stderr, "Errore nei vincoli");
        return -1;
    }

    int xyz[N][3];
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d %d %d\n", &xyz[i][0], &xyz[i][1], &xyz[i][2]);
    }
    int u[Q], j, f;
    for (i = Q; i > 0; i--) // ho dovuto fare il ciclo al contrario senno' mi dava i risultati al oirartnoc
    {
        fscanf(input, "%d\n", &u[i]);
        if (u[i] < 0)
        {
            fprintf(stderr, "Errore nei vincoli");
            return -1;
        }
        j = 0;

        for (f = 0; f < N; f++)
        {
            distanza = sqrt(pow(xyz[f][0], 2) + pow(xyz[f][1], 2) + pow(xyz[f][2], 2));
            if (xyz[f][0] > 1073741824 || xyz[f][0] < -1073741824 || xyz[f][1] > 1073741824 || xyz[f][1] < -1073741824 || xyz[f][2] > 1073741824 || xyz[f][2] < -1073741824)
            {
                fprintf(stderr, "Errore nei vincoli");
                return -1;
            }
            if (distanza - u[i] <= 0)
                j++;
        }

        fprintf(output, "%d\n", j);
    }

    fclose(input);
    fclose(output);
    return 0;
}