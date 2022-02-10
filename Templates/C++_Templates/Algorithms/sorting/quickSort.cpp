// include Partition template

template <class T>
class QuickSort{
public:
    // right = n - 1
    T quickLomuto(T* arr, T left, T right);
    T quickHoarse(T* arr, T left, T right);
};

template<class T>
T QuickSort<T>::quickLomuto(T *arr, T left, T right) {
    if (left < right){
        Partition<T> part;
        T pivot = part.lomutoPartition(arr, left, right);
        quickLomuto(arr, left, pivot - 1);
        quickLomuto(arr, pivot + 1, right);
    }
}

template<class T>
T QuickSort<T>::quickHoarse(T *arr, T left, T right) {
    if (left < right){
        Partition<T> part;
        T pivot = part.hoarePartition(arr, left, right);
        quickHoarse(arr, left, pivot);
        quickHoarse(arr, pivot + 1, right);
    }
}
