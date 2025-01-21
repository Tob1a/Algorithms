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
List *AggList(List *ciaone, int a, int b); // int b

void freememory(List *ciaone)
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
    free(ciaone);
}

int input()
{
    FILE *input = fopen("input.txt", "r");
    int N, M, a, b;
    fscanf(input, "%d %d\n", &N, &M);
    List *ciaone = (List *)malloc(sizeof(List));
    ciaone = NULL;
    // inizializzazione null
    for (unsigned int i = 0; i < M; i++)
    {
        fscanf(input, "%d %d\n", &a, &b);
        // sarebbe
        // uso la variabile b per metterci il risultato

        ciaone = AggList(ciaone, a, b);
        if (ciaone == NULL)
        {
            // freememory(ciaone);
            fclose(input);
            return 2;
        }
        ciaone = AggList(ciaone, b, a);
        if (ciaone == NULL)
        {
            // freememory(ciaone);
            fclose(input);
            return 2;
        }
    }
    // freememory(ciaone);
    fclose(input);
    return 0;
}

void stampa(int ris)
{
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", ris > 0 ? "TRUE" : "FALSE");
    fclose(output);
}

int main()
{
    int ris;
    ris = input();
    stampa(ris);
    return 0;
}

List *AggList(List *ciaone, int a, int b) // int b
{
    List *destlist, *srclist;
    Nodo *srcl;
    if (ciaone == NULL) // se la lista e' vuota
    {
        srclist = (List *)malloc(sizeof(List));
        srclist->id = a;
        srclist->suc = NULL;
        ciaone = srclist;
        // creo Nodo

        srcl = (Nodo *)malloc(sizeof(Nodo)); // src punta verso un nodo che ha appena creato con la malloc solo se la lista e' vuota del nodo a
        srcl->id = b;
        srcl->nodisuc = NULL;
        ciaone->head = srcl;
    }
    else
    {
        destlist = (List *)malloc(sizeof(List));
        destlist->id = a;
        destlist->suc = NULL;
        // creo il nodo se e' vuoto

        srcl = (Nodo *)malloc(sizeof(Nodo)); // src punta verso un nodo che ha appena creato con la malloc solo se la lista e' vuota del nodo a
        srcl->id = b;
        srcl->nodisuc = NULL;
        destlist->head = srcl;

        // eseguo controlli su questo ciaone
        srclist = ciaone; // sarebbe ciaone->suc

        while (srclist->suc != NULL)
        {
            if (srclist->id == a) // se trovo già il valore che devo mettere inizio con i nodi
            {
                // srclist e' il mio nuovo ciaone
                //  qua inizio il mio lavoro
                Nodo *dest, *src; // cambia il nome delle variabili src e dest

                dest = (Nodo *)malloc(sizeof(Nodo)); // dest punta verso un nuovo nodo appena creato
                dest->id = b;
                dest->nodisuc = NULL;
                src = (Nodo *)malloc(sizeof(Nodo));
                src = srclist->head;
                // ok qua ho memorizzato il nodo a

                while (src->nodisuc != NULL) // scorro finche non trovo null
                {
                    // controllo se esiste un valore uguale nella lista degli archi
                    if (src->id == b)
                        return NULL; // dovrei fare output
                    // vado al nodo successivo
                    src = src->nodisuc;
                }
                if (src->id == b)
                    return NULL; // dovrei fare output
                src->nodisuc = dest;
                srclist->head = src; // da provare
                return ciaone;
            }
            srclist = srclist->suc;
        }
        if (srclist->id == a) // se trovo già il valore che devo mettere inizio con i nodi
        {
            // srclist e' il mio nuovo ciaone
            //  qua inizio il mio lavoro
            Nodo *dest, *src; // cambia il nome delle variabili src e dest

            dest = (Nodo *)malloc(sizeof(Nodo)); // dest punta verso un nuovo nodo appena creato
            dest->id = b;
            dest->nodisuc = NULL;
            src = (Nodo *)malloc(sizeof(Nodo));
            src = srclist->head;
            // ok qua ho memorizzato il nodo a

            while (src->nodisuc != NULL) // scorro finche non trovo null
            {
                // controllo se esiste un valore uguale nella lista degli archi
                if (src->id == b)
                    return NULL; // dovrei fare output
                // vado al nodo successivo
                src = src->nodisuc;
            }
            if (src->id == b)
                return NULL; // dovrei fare output
            src->nodisuc = dest;
            return ciaone; // dovrebbe essere ciaone.head=src.nodisuc;return ciaone;
        }
        srclist->suc = destlist;
    }
    return ciaone;
}