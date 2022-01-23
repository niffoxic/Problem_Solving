
template<class T>
void insertionSort(T *arr, T n)
{
    for(T i = 1; i < n; i++)
    {
        T key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j], j--;
        arr[j + 1] = key;
    }
}
