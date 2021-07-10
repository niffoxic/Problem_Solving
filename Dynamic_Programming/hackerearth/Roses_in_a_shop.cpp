const int dp6 = 1e5;
int dp[dp6];
int sp[dp6];

int roses(int const arr[], int n){
    dp[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if (arr[i] > arr[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    sp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        if (arr[i] < arr[i + 1]) sp[i] = sp[i + 1] + 1;
        else sp[i] = 1;
        ans = max(ans, sp[i]);
    }
    for(int i = 1; i < n - 1; i++){
        if (arr[i - 1] < arr[i + 1]) ans = max(ans, dp[i - 1] + sp[i + 1]);
    }
    return ans;
}
