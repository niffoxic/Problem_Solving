// Minimum number of coins
int minCoinsSolve(int const coins[], int m, int n){
    if (n == 0) return 0;
    if (m == 0) return INT_MAX - 1;
    int left = INT_MAX - 1, right = INT_MAX - 1;
    if (n - coins[m - 1] >= 0) left = 1 + minCoinsSolve(coins, m - 1, n - coins[m - 1]);
    right = minCoinsSolve(coins, m - 1, n);
    return min(left, right);
}
// DP
int minCoins(int const coins[], int m, int n){
    int dp[n + 1]; for(int i = 0 ; i <= n; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if (i - coins[j] >= 0){
                int res = dp[i - coins[j]];
                if (res != INT_MAX){
                    dp[i] = min(dp[i], res + 1);
                }
            }
        }
    }
    return dp[n] == INT_MAX?-1:dp[n];
}
