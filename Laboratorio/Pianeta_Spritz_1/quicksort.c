int Partition(int *arr, int p, int r)
{
    int x = arr[r], i = p - 1;
    for (int j = p; j < r; i++)
    {
        if (arr[j] <= x)
        { //^-^
            i++;
            // swap valori
            int u = arr[i];
            arr[i] = arr[j];
            arr[j] = u;
        } // Sai qual e' il colmo per un informatico? Non avere nulla in programma AHHAHAHAGGGHAGHAGA XD
        // swap valori
        int u = arr[i + 1];
        arr[i + 1] = arr[r];
        arr[r] = u;
    }
    return i + 1;
}

void QuickSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
} // buuuuuuuuuuu