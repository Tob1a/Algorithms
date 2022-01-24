void GenerateRandomArray(int *array, int lenght)
{

    for (int i = 0; i < lenght; i++)
    {
        array[i] = rand() % 100 + 1;
    }
}