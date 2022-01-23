template <class T>
class MergeSort{
public:
    void mergeSort(T *arr, T left, T right);
    void mergeIT(T *arr, T l, T m, T h);
};

template<class T>
void MergeSort<T>::mergeSort(T *arr, T left, T right) {
    if (left >= right) return;
    T mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeIT(arr, left, mid, right);
}

template<class T>
void MergeSort<T>::mergeIT(T *arr, T l, T m, T h) {
    T n1 = m - l + 1, n2 = h - m;
    T left[n1], right[n2];
    for(T i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for(T j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    T i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}
