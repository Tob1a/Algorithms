#include <stdio.h>

int main(void)
{
    // inizio apertura file input e output
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "r");
    if (input == NULL || output == NULL)
    {
        fprintf(stderr, "I/O Error");
        return -1;
    }
    int N, Q, sni = 9999, i = 0, j = 0;
    fscanf(input, "%d %d /n", &N, &Q);
    int arrayQ[Q];
    // fine apertura
    // inizio controlli N e Q
    if (1 > N || N > 10000 || 1 > Q || Q > 10000)
    {
        fprintf(output, "Errore nei vincoli");
        return -1;
    }
    // fine controlli N e Q
    //  inizio algoritmo lettura
    int arrray[N][sni];
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d ", &arrray[i][0]);
        if (arrray[i][0] < -2147483648)
        {
            fprintf(output, "Errore nei vincoli dell'id");
            return -1;
        }
        fscanf(input, "%d", &arrray[i][1]);
        if (arrray[i][1] < 1 || arrray[i][1] > 10000)
        {
            fprintf(output, "Errore nei vincoli di s");
            return -1;
        }
        for (j = 1; j < arrray[i][1]; j++)
        {
            fscanf(input, "%d ", &arrray[i][j]);
            if (arrray[i][j] >= 2147483647)
            {
                fprintf(output, "Errore nei vincoli di x");
                return -1;
            }
        }
        fscanf(input, "\n");
    }
    for (i = 0; i < Q; i++)
    {
        fscanf(input, "%d", &arrayQ[i]);
    }
    //  inizio ordinamento
    for (i = 0; i < N; i++)
    {
        for (j = 2; j < arrray[i][1]; j++)
        {
            int key = arrray[i][j];
            int u = j - 1;
            while (u > 0 && arrray[i][j] > key)
            {
                arrray[i][u + 1] = arrray[i][u];
                u--;
            }
            arrray[i][u + 1] = key;
        }
    }
    // provo dopos ordinamento

    for (i = 0; i < Q; i++)
    {
        for (int f = 0; i < N + 1; i++)
        {
            for (j = 2; j < arrray[i][0].lenght() - 1; j++)
            {
                if (arrray[f][j] == arrayQ[i])
                {
                    fprintf(output, "%d ", arrray[N - 1][0]);
                    break;
                }
            }
            fscanf(input, "\n");
        }
    }
    // inizio output
    fclose(input);
    fclose(output);
    return 0;
}