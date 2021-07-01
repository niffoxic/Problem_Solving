// Recursion
int minDifferenceSolve(int arr[], int n, int sum, int current) {
    if (n == 0) return abs(abs(current - sum) - current);
    return min(minDifferenceSolve(arr, n - 1, sum, current + arr[n - 1]),
               minDifferenceSolve(arr, n - 1, sum, current));
}

// DP
int minDifference(int const arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 1; i <= sum; i++) dp[0][i] = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0){
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    int diff = INT_MAX;

    for(int i = sum/2; i >= 0; i--){
        if (dp[n][i])
            return diff = sum - 2 * i;
    }
    return sum;
}
