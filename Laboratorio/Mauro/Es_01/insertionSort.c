void insertionSort(int *arr, int start, int size)
{
    for (int f = 1; f < size; f++)
    {
        int key = arr[f];
        int u = f - 1;
        while (u >= 0 && arr[u] > key)
        {
            arr[u + 1] = arr[u];
            u = u - 1;
        }
        arr[u + 1] = key;
    }
}