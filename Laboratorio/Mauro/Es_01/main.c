#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort.c"
#include "../Es_02/merge.c"

typedef struct
{
    int min_size, max_size /**/, step, repetition, seed /*seme di generazione di numeri*/;
} configuration;

configuration init()
{
    configuration config;
    config.min_size = 10;
    config.max_size = 1000;
    config.repetition = 50;
    config.step = 10;
    config.seed = 362372;
    return config;
}

int check(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            printf("Errore nell'ordinamento");
            return -1;
        }
    }
    return 1;
}

double run(size_t size, int repetition, int o)
{

    double elapsed_time = 0.0;
    for (int i = 0; i < repetition; i++)
    {
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand();
            // inizializzo array
        }
        // riordino

        clock_t start = clock();
        if (o == 2)
            insertionSort(arr, 0, size);
        else
            merge_sort(arr, 0, size - 1);
        clock_t end = clock();

        if (check(arr, size) != 1)
        {
            printf("\nL'ordinamento e' scorretto\n");
            exit(-1);
        }

        elapsed_time += ((end - start) / (double)(CLOCKS_PER_SEC));
    }

    return elapsed_time;
}

void run_experiments(configuration config)
{
    int o;
    printf("Merge scrivi 1, Insertion scrivi 2:\n");
    scanf("%d", &o);
    for (int i = config.min_size; i < config.max_size; i += config.step)
    {
        srand(config.seed);
        double elapsed_time = run(i, config.repetition, o);
        printf("%lf\n", elapsed_time);
        config.seed++;
    }
}

int main(void)
{
    configuration config = init();
    run_experiments(config);
    return 0;
}
