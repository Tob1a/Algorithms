void HybridSort(A, p, r)
{
    if (r - p + 1 > k)
    {
        q = (p + r) / 2;
        HybridSort(A, p, q);
        HybridSort(A, q + 1, r);
    }
}