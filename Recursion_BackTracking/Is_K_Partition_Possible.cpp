// BackTracking Solution
bool solve(int arr[], int n, int *used, int k, int current, int target, int index){
    if (k == 1) return true;
    if (current == target) return solve(arr, n, used, k - 1, 0, target, 0);

    for(int i = index; i <n; i++){
        if (!used[i]){
            used[i] = 1;
            if (solve(arr, n, used, k, current + arr[i], target, i + 1)){
                return true;
            }
            used[i] = 0;
        }
    }
    return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    int target = 0; int *used = new int[n];
    for(int i = 0; i < n; i++){
        target += a[i];
        used[i] = false;
    }
    if (k == 0 || target % k) return false;
    target /= k;
    return solve(a, n, used, k, 0, target, 0);
}
