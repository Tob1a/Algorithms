#include <stdio.h>
// shortcut shift alt
int main(void)
{

    // apri file in lettura e scrittura

    FILE *open_fp = fopen("input.txt", "r");
    FILE *close_fp = fopen("output.txt", "w");
    int ans = 1, n;

    // leggi i dati con fscanf

    fscanf(open_fp, "%d", &n); // restituisce il tipo di file e dove metterlo

    // risolvi il problema

    while (n != 1)
    {

        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;

        ++ans;
    }
    // stampa il risultato con fprintf

    fprintf(close_fp, "%d", ans);
    fclose(open_fp);
    fclose(close_fp);
    return 0;

    // chiudi il file e restituisci 0
}