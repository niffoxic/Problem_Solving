
// Recursion
int solve(int price[], int n, int weight[], int w){
    if (n == 0 || w == 0) return 0;
    int left = 0, right = 0;
    if (w - weight[n - 1] >= 0) left = price[n - 1] + solve(price, n, weight, w - weight[n - 1]);
    right = solve(price, n - 1, weight, w);
    return max(left, right);
}

// Converted into DP
int cutRod(int price[], int n){
    int w[n]; for(int i = 0; i < n; i++) w[i] = i + 1;
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= n; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (j >= w[i - 1]){
                dp[i][j] = max(price[i - 1] + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
}
