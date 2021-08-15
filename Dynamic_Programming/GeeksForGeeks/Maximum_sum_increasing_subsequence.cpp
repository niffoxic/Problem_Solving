int maxSumIS(int arr[], int n)
{
    vector<int>dp(arr, arr + n);

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
