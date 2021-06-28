
long long dp[1001][1001];

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
