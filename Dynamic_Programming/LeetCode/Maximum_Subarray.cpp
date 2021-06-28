
// Maximum Subarray sum
int top_kadane(int const arr[], int n){
    int dp[n]; dp[0] = arr[0] > 0? arr[0]: 0;
    int res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0) dp[i] = 0;
        res = max(dp[i], res);
    }
    return res;
}

// Optimised
long long maxSubArray(vector<int>& nums) {
    long long total = INT_MIN;
    long long res = INT_MIN;
    for(int num : nums){
        total = num > total + num? num: total + num;
        res = res > total? res: total;
    }

    return res;
}
