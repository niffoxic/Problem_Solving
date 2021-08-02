int maxProfit(int k, int n, int arr[]) {
        // code here
        if (n == 0) return 0;
        int dp[k + 1][n + 1];
        for(int i = 0; i <= k; i++) for(int j = 0; j <= n; j++) dp[i][j] = 0;
        
        for(int t = 1; t <= k; t++){
            int max_val = INT_MIN;
            for(int d = 1; d <= n; d++){
                max_val = max(max_val, dp[t - 1][d - 1] - arr[d - 1]);
                dp[t][d] = max(dp[t][d - 1], max_val + arr[d]);
            }
        }
        
        return dp[k][n - 1];
}
