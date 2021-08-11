const int dp_size = 1e5;

// recursion
int dp_rec[dp_size];
int longest_increasing_subsequence(int arr[], int prev, int curr, int n) {
    if (curr == n)
        return 0;
    int left = 0;
    if (prev == -1 || curr > prev)
        left = 1 + longest_increasing_subsequence(arr, curr, curr + 1, n);
    int right = longest_increasing_subsequence(arr, prev, curr, n);
    return max(left, right);
}
// dp
int longest_increasing_subsequence_dp(int arr[], int n){
    int dp[n + 1];
    dp[0] = 1;
    int res = 0;
    for(int i = 1; i < n; i++){
        int max_val = 0;
        for(int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                if (dp[j] > max_val)
                    max_val = dp[j];
            }
        }
        dp[i] = max_val + 1;
        res = max(res, dp[i]);
    }
    return res;
}

// dp
int longest_increasing_subsequence_BINdp(int arr[], int n){
    int dp[n + 1];
    for(int i = 1; i <= n; i++) dp[i] = INT_MAX;
    dp[0] = INT_MIN;
    for(int i = 0; i < n; i++){
        int idx = upper_bound(dp, dp + n + 1, arr[i]) - dp;
        if (arr[i] > dp[idx - 1] && arr[i] < dp[idx])
            dp[idx] = arr[i];
    }
    int max_a = 0;
    for(int i = n; i >= 0; i--){
        if (dp[i] != INT_MAX){
            max_a = i;
            break;
        }
    }
    return max_a;
}
