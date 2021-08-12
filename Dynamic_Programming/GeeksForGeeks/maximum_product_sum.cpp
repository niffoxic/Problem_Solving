// Vairation of kadanes algorithm
long long maxProduct(int *arr, int n){
    long long res = arr[0];
    long long max_val = arr[0], min_val = arr[0];
    for(int i = 1; i < n; i++){

        if (arr[i] < 0)
            swap(max_val, min_val);

        max_val = max((long long)arr[i], (long long)max_val * arr[i]);
        min_val = min((long long)arr[i], (long long)min_val * arr[i]);

        res = max(res, max_val);
    }
    return res;
}
