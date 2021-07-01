// DP
int subset_with_k_diff_dp(int const arr[], int n, int diff){
    int sum = 0; for(int i = 0; i < n; i++) sum += arr[i];
    int target_sum = (sum + diff) / 2;

    int dp[n + 1][target_sum + 1];
    for(int i = 0; i <= target_sum; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if (j - arr[i - 1] >= 0){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
