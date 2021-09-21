long long countWays(int m)
    {
        // your code here
        const int mod = 1e9+7;
        long long dp[m + 1];
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= m; i++)
            dp[i] = (dp[i - 2] + 1) % mod;
        return dp[m];
    }
