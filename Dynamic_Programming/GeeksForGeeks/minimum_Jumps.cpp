 // ---------------------------------------Recursive solution ( slow ) Solution 1------------------------------------------------
int dp7[10000000];
int minJumpsRecursion(int arr[], int n) {
    if (n == 1) return 0;

    if (dp7[n - 1] != -1) return dp7[n - 1];

    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (i + arr[i] >= n - 1) {
            int current = minJumpsRecursion(arr, i + 1);
            if (current != INT_MAX) {
                res = min(res, current + 1);
            }
        }
    }
    return dp7[n - 1] = res;
}

int minJump(int arr[], int n) {
    for (int i = 0; i < 10000000; i++) dp7[i] = -1;
    return minJumpsRecursion(arr, n);
}
 // ---------------------------------------Recursive solution ( little faster ) Solution 2 ------------------------------------------
// Bottom Up DP
int minJumps(int arr[], int n) {
    int* dp8 = new int[n];
    dp8[0] = 0;
    for (int i = 1; i < n; i++) dp8[i] = INT_MAX;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] + j >= i) {
                if (dp8[j] != INT_MAX) {
                    dp8[i] = min(dp8[i], dp8[j] + 1);
                }
            }
        }
    }
    return dp8[n - 1] == INT_MAX ? -1 : dp8[n - 1];
}
 // ---------------------------------------Recursive solution ( Fast ) Solution 3------------------------------------------------
// Optimised

int minJumps(int arr[], int n) {
    int j = 0, c = 0, cf = 0;
    for (int i = 0; i < n; i++) {
        cf = max(cf, i + arr[i]);
        if (i == c) {
            j++;
            c = cf;
        }
        if (c >= n - 1) break;
    }
    return c < n - 1 ? -1 : j;
}
