using ll = long long;

int rec(int n) {
    if (n == 1) return 0;
    int l3 = (n % 3 == 0)? 1 + rec(n / 3): INT_MAX - 10;
    int l2 = (n % 2 == 0)? 1 + rec(n / 2) : INT_MAX - 10;
    int l1 = 1 + rec(n - 1);
    return min(l2, min(l1, l3));
}

ll rec_dp(ll n) {
    ll *dp = new ll[n + 1];
    dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        dp[i] = INT_MAX;
        if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3]);
        if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2]);
        dp[i] = min(dp[i], dp[i - 1]) + 1;
    }
    return dp[n];
}
