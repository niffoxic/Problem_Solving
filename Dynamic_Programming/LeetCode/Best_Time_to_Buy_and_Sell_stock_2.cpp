// Bottom Top DP
int maxProfit(vector<int>& prices){
    int n = prices.size(); int dp[n]; dp[0] = 0;
    for(int i = 1; i < n; i++) dp[i] = dp[i - 1] + (prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0);
    return dp[n - 1];
}

// optimised
int maxProfit2(vector<int>& prices){
    int n = prices.size(); int res = 0;
    for(int i = 1; i < n; i++) res += max(0, prices[i] - prices[i - 1]);
    return res;
}
