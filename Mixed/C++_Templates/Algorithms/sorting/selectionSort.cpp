template <class T>
void selectionSort(T *arr, T n)
{
    for(T i = 0; i < n; i++)
    {
        T min_index = i;
        for(T j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index]) min_index = j;
        swap(arr[i], arr[min_index]);
    }
}
