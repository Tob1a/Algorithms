// questo e' un mergeSort

/**
 * ciao
 * come va? per fare questa cosa devi fare slash**
 *
 */

void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j, left[n1], right[n2];

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[start + 1];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    for (int k = start; k <= end; k++)
    {
        if (i < n1)
        {
            if (j < n2)
            {
                arr[k] = (left[i] < right[j]) ? left[i++] : right[j++];
                /**
                 * sarebbe:
                 * if(left[i]<right[j]){
                 * arr[k]=left[i];
                 * i++;}
                 * else{
                 * }
                 */
            }
            else
            {
                arr[k] = left[i++];
            }
        }
        else
        {
            arr[k] = right[j++];
        }
    }
}

void merge_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    // se non c'e codice qua sotto significa che il mio array e' lungo 1
}

// presa una stringa posso dare una determinata funzione

/**
 * typedef void (*algo_ptr)(int *,int,int);
algo_ptr select_algorithm(char *algo_name){
    if(strcmp(algo_name,"INSERTION")){
        return &insertionSort;

    }else if(strcmp(algo_name,"MERGE")){
        return &merge_sort;
    }else{
        printf("Errore - l'algoritmo %s non esiste.",algo_name);
    }
}
*/
