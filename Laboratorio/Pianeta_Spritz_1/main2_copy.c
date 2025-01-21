#include <stdio.h>
#include <math.h>

// metodi

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int N, Q, i;

    fscanf(input, "%d %d\n", &N, &Q);

    // vincoli

    double distanze[N];
    int a, b, c;
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d %d %d\n", &a, &b, &c);
        distanze[i] = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    }
    int u, j, f;
    for (i = Q; i > 0; i--) // ho dovuto fare il ciclo al contrario senno' mi dava i risultati al oirartnoc
    {
        fscanf(input, "%d\n", &u);
        j = 0;

        for (f = 0; f < N; f++)
        {
            if (distanze[f] <= u)
                j++;
        }

        fprintf(output, "%d\n", j);
    }

    fclose(input);
    fclose(output);
    return 0;
}