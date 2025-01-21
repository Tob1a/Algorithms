#include <stdio.h>
#include <math.h>

// metodi

int binarySearch(double *arr, int l, int r, double x)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m + 1;

        // If x greater, ignore left half
        if (arr[m] < x)
        {
            l = m + 1; // funzia
        }              // lorenzo.garbellini99@gmail.com
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return l; // ho messo al posto di m+1 l e funziona tutto
}

void merge(double *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int i, j;
    double left[n1], right[n2];

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }

    for (j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    i = j = 0;

    for (int k = start; k <= end; k++)
    {
        if (i < n1)
        {
            if (j < n2)
            {
                arr[k] = (left[i] <= right[j]) ? left[i++] : right[j++];
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

/**
 * Implementazione di `merge sort`.
 */
void merge_sort(double *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(void)
{
    FILE *input = fopen("input.txt", "r");

    int N, Q, i;

    fscanf(input, "%d %d\n", &N, &Q);

    double distanze[N], u;
    int a, b, c;
    for (i = 0; i < N; i++)
    {
        fscanf(input, "%d %d %d\n", &a, &b, &c);
        distanze[i] = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
        // qui funziona
    }

    FILE *output = fopen("output.txt", "w");

    merge_sort(distanze, 0, N - 1);

    for (i = 0; i < Q; i++)
    {
        fscanf(input, "%d\n", &a);
        u = (double)a;
        fprintf(output, "%d\n", binarySearch(distanze, 0, N - 1, u));
    }
    fclose(input);
    fclose(output);
    return 0;
}