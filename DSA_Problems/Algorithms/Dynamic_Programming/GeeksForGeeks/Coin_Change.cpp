
long long dp[1001][1001];
// Top bottom DP
long long int rcount(int const coins[], int m, int n){
    if (n == 0) return 1; if (m == 0) return 0;
    if (dp[n][m]) return dp[n][m];
    long long res = rcount(coins, m - 1, n);
    if (n - coins[m - 1] >= 0){
        res += rcount(coins, m, n - coins[m - 1]);
    }
    return dp[n][m] = res;
}

long long int count(int c[], int m, int n){
    for(auto & i : dp) for(long long & j : i) j = 0;
    return rcount(c, m, n);
}


// bottom up DP 

long long count1(int const coins[], int m, int n){
    for(auto & i : dp) for(long long & j : i) j = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j - 1];
            if (i - coins[j - 1] >= 0){
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[n][m];
}
