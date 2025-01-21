// ciao grafo :)
// non mi conviene usare una matrice di adicenza poiche sarebbe sparsa, uso le liste di adiacenza;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Aggiungo metodi per grafo

int input()
{
    FILE *input = fopen("input.txt", "r");
    int N, M, a, b;
    fscanf(input, "%d %d\n", &N, &M);
    bool(*ciaone)[N] = malloc(sizeof(bool[N][N]));
    for (unsigned int i = 0; i < N; i++)
        for (unsigned int j = 0; j < N; j++)
            ciaone[i][j] = true;

    for (unsigned int i = 0; i < M; i++)
    {
        fscanf(input, "%d %d\n", &a, &b);
        // sarebbe
        if (ciaone[a][b] == false || ciaone[b][a] == false)
        {
            fclose(input);
            free(ciaone);
            return 1;
        }
        ciaone[a][b] = false;
        ciaone[b][a] = false;
    }
    fclose(input);
    free(ciaone);
    return 0;
}

void stampa(int ris)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", ris >= 1 ? "TRUE" : "FALSE");
    fclose(output);
}

int main()
{
    int ris;
    ris = input();
    stampa(ris);
    return 0;
}