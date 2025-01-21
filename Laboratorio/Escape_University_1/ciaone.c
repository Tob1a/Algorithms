#include <stdio.h>
#include <stdlib.h>
#define Max_Size 1000 * 1000
struct coppia
{
    int numero; // numero della riga
    int id;
};

int main(void)
{
    struct coppia pairs[Max_Size];
    FILE *input = fopen("input.txt", "r"), *output = fopen("output.txt", "w");
    int N, Q, id, s;
    fscanf("%d %d", N, Q);
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        fscanf("%d %d\n", id, s);
        for (int j = 0; j < s; j++)
        {
            fscanf("%d ", &pairs[size].numero);
            pairs[size].id = id;
            size++;
        }
    }
    return 0;
}