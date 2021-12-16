// top bottom DP
int solve(int n, int dp[]){
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dp[n]) return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs1(int n){
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++) dp[i] = 0;
    int res = solve(n, dp);
    return res;
}

// Bottom UP DP
int climbStairs2(int n){
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++) dp[i] = 0;
    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Optimised
int climbStairs3(int n){
    int prev = 1, current = 1;
    for(int i = 2; i <= n; i++){
        int temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}
