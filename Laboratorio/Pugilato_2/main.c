// ciao grafo :)
// non mi conviene usare una matrice di adicenza poiche sarebbe sparsa, uso le liste di adiacenza;
#include <stdio.h>
#include <stdlib.h>

// Inizio struct per grafo

typedef struct Nodo
{
    int id;
    struct Nodo *nodisuc; // archi uscenti dal nodo
} Nodo;

typedef struct List
{
    int id;
    Nodo *head;
    struct List *suc;
} List;

// esempio nodo 1 arco to2 arco to3 arco to4
//         nodo 2 arcoto1 arco to3 ...

// Aggiungo metodi per grafo

void AggList(List *ciaone, int a)
{
    List *dest, *src;
    if (ciaone->suc == NULL)
    {
        src = (List *)malloc(sizeof(List));
        src->id = a;
        src->suc = NULL;
        src->head = NULL;
        ciaone->suc = src;
    }
    else
    {
        dest = (List *)malloc(sizeof(List));
        dest->id = a;
        dest->suc = NULL;
        dest->head = NULL;
        src = ciaone->head;
        while (src->suc != NULL)
        {
            if (src->id == a)
            {
                // qua inizio il mio lavoro

                return *src;
            }
            src = src->suc;
        }
        src->suc = dest;
    }
}

int AggNodo(int a, int b, List *ciaone1, List *ciaone2)
{

    Nodo *dest, *src;
    if (ciaone1->head == NULL) //
    {
        src = (Nodo *)malloc(sizeof(Nodo)); // src punta verso un nodo che ha appena creato con la malloc solo se la lista e' vuota del nodo a
        src->id = b;
        src->nodisuc = NULL;
        ciaone1->head = src; // al posto di src metti head dell'array

        // in tutto questo ho memorizzato il nodo b
    }
    else
    {
        dest = (Nodo *)malloc(sizeof(Nodo)); // dest punta verso un nuovo nodo appena creato
        dest->id = a;
        dest->nodisuc = NULL;
        src = ciaone1->head;
        // ok qua ho memorizzato il nodo a

        while (src->nodisuc != NULL) // scorro finche non trovo null
        {
            // controllo se esiste un valore uguale nella lista degli archi
            if (src->id == b)
                return 2;
            // vado al nodo successivo
            src = src->nodisuc;
        }
        src->nodisuc = dest;
    }

    // ho fatto tutto questo ma non so se devo controllare anche il nodo inverso

    if (ciaone2->head == NULL) //
    {
        src = (Nodo *)malloc(sizeof(Nodo)); // bla bla bla
        src->id = a;
        src->nodisuc = NULL;
        ciaone2->head = src; // bla bla bla

        // bla bla bla
    }
    else
    {
        dest = (Nodo *)malloc(sizeof(Nodo)); // bla bla bla
        dest->id = b;
        dest->nodisuc = NULL;
        src = ciaone2->head;
        // bla bla bla

        while (src->nodisuc != NULL) // bla bla bla
        {
            // bla bla bla
            if (src->id == a)
                return 2;
            // bla bla bla
            src = src->nodisuc;
        }
        src->nodisuc = dest;
    }
    return 0;
}

void freememory(List *ciaone, int n)
{
    List *c, *d;
    Nodo *a, *b; // 2 puntatore a e b verso un nodo
    c = ciaone->suc;
    while (c != NULL)
    {
        a = c->head;
        while (a != NULL)
        {
            b = a;
            a = a->nodisuc;
            free(b);
        }
        d = c;
        c = c->suc;
        free(d);
    }
}

int input()
{
    FILE *input = fopen("input.txt", "r");
    int N, M, a, b;
    fscanf(input, "%d %d\n", &N, &M);
    List *ciaone;
    ciaone->suc = NULL;
    ciaone->head = NULL;
    // inizializzazione null
    for (unsigned int i = 0; i < M; i++)
    {
        fscanf(input, "%d %d\n", &a, &b);
        // sarebbe
        // uso la variabile b per metterci il risultato

        b = AggNodo(a, b, ciao1, ciao2);
        if (b != 0)
        {
            freememory(&ciaone, M);
            fclose(input);
            return b;
        }
    }
    freememory(&ciaone, M);
    fclose(input);
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
