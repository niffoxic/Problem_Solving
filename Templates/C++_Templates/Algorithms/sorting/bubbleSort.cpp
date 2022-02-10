template <class T>
void bubbleSort(T *arr, T n)
{
    for(T i = 0; i < n; i++)
    {
        bool swapped = false;
        for(T j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swapped = true, swap(arr[j], arr[j + 1]);
        if (!swapped) break;
    }
}
