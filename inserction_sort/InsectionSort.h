void InsectionSort(int *array, int lenght)
{
    int key, i;
    for (int j = 2; j < lenght; j++)
    {
        key = array[j];
        i = j - 1;
        while (i > 0 && array[j] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}