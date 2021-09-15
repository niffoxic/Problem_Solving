int Hoare(int *arr, int start, int end){
    int pivot = arr[start];
    int i = start - 1, j = start;
    while(j <= end){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[start], arr[i]);
    return i;
}

void quickSort(int *arr, int left, int right){
    if (left == right) return;
    int p = Hoare(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
}


void solve(int case_no){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << ((i == n - 1)?"":" ");
}
