
// dopo averlo fatto come lo vuoi tu

// dovrai cercare di trovare una cosa sensata

// per evitare un ciclo aggiuntivo eseguo uno stack con dentro gli indici dei valori

// creazione stack
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
// mauro non e' come il tuo, e' quasi perfetto

// size_t e' un tipo di dato unsigned long

void push(int *arr, int *top, int i)
{
    if (*top == SIZE)
    {
        printf("\n Overload");
        exit(1);
    }
    (*top)++;
    arr[*top] = i;
}

void pop(int *top)
{
    if (*top == -1)
    {
        printf("\n Underflow");
        exit(1);
    }
    (*top)--;
}

int read(int *arr, int top)
{
    if (top == -1)
    {
        return 0;
    }
    return arr[top];
}

int main(void)
{

    FILE *input = fopen("input.txt", "r");
    int N, i = 0, f, area = 0, areap = 0, top = -1, prec;
    ;
    fscanf(input, "%d\n", &N);

    int istogramma[N];
    for (unsigned int i = 0; i < N; i++)
    {
        fscanf(input, "%d ", istogramma + i); // istogramma+i sarebbe come dire &istogramma[i]
    }

    // inizializzazione stack
    int arr[SIZE];
    // il mio scopo e' quello di andare a mettere i miei elementi in un array e poi andare a fare il confronto tra essi e il push
    while (i < N)
    {
        if (top == -1 || istogramma[read(arr, top)] <= istogramma[i]) // se l'elemento scansionato e' maggiore a quello nello stack PUSH
        {
            push(arr, &top, i); // dentro mi salvo il numero del ciclo
            i++;
        }
        else
        {
            // svuotamento dello stack
            prec = read(arr, top);
            pop(&top);

            if (top == -1)                   // questo if sarebbe area=read(arr,top)*( top==-1 ? i : i-peak-1)
                area = i * istogramma[prec]; // il peek di mauro ritorna il top in quel preciso istante
            else
                area = istogramma[prec] * (i - read(arr, top) - 1);
            if (areap < area)
                areap = area;
        }
    }
    while (top != -1)
    {
        prec = read(arr, top);
        pop(&top);
        if (top == -1) // questo if sarebbe area=read(arr,top)*( top==-1 ? 1 : i-peak-1)
            area = i * istogramma[prec];
        else
            area = istogramma[prec] * (i - read(arr, top) - 1);
        if (areap < area)
            areap = area;
    }

    fclose(input);

    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%d", areap);
    fclose(output);
    return 0;
}
