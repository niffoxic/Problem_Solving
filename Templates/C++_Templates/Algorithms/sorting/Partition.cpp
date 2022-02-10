#include <bits/stdc++.h>
using namespace std;


template <class T>
class Partition{
public:
    // takes right - 1 if right = n (where n is the size of the array)
    T hoarePartition(T *arr, T left, T right);
    T lomutoPartition(T *arr, T left, T right);
    T naivePartition(T *arr, T left, T right, T p);
};

template<class T>
T Partition<T>::hoarePartition(T *arr, T left, T right) {
    T p = arr[left];
    T i = left - 1, j = right + 1;
    while (true)
    {
        do {
            i++;
        }while (arr[i] < p);
        do {
            j--;
        }while (arr[j] > p);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

template<class T>
T Partition<T>::lomutoPartition(T *arr, T left, T right) {
    T p = arr[right], i = left - 1;
    for(T j = left; j < right; j++)
        if(arr[j] < p) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

template<class T>
T Partition<T>::naivePartition(T *arr, T left, T right, T p) {
    T temp[right - left + 1], index = 0;
    for(T i = left; i <= right; i++)
        if (arr[i] <= arr[p] && i != p)
            temp[index] = arr[i], index++;
    temp[index++] = arr[p];
    for(T i = left; i <= right; i++)
        if (arr[i] < arr[p])
            temp[index] = arr[i], index++;
    for(T i = left; i <= right; i++)
        arr[i] = temp[i - left];
}
