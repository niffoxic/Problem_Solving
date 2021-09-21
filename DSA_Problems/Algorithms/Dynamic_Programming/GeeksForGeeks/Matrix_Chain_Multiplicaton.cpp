int dp[501][501];
// Matrix chain multiplication aka MCM
int solve(int n, int arr[], int i, int j)
{
    if (i >= j) return 0;
    int res = INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];

    for(int k = i; k < j; k++){
        int sub = solve(n, arr, i, k) + solve(n, arr, k + 1, j) +
                arr[i - 1] * arr[k] * arr[j];
        res = min(res, sub);
    }

    return dp[i][j] = res;
}

int matrixMultiplication(int n, int arr[]){
    for(int i = 0; i<= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = -1;
    }
    return solve(n, arr, 0, n - 1);
}
