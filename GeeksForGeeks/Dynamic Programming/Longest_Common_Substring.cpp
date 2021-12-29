// Recursion
int lcs(str *s1, str *s2, int n, int m){
    if (n == 0 || m == 0) return 0;

    if (s1[n - 1] == s2[m - 1])
        return 1 + lcs(s1, s2, n - 1, m - 1);

    int left = lcs(s1, s2, n - 1, m);
    int right = lcs(s1, s2, n, m - 1);

    return max(left, right);
}

// DP
int longestCommonSubstr(string &s1, string &s2, int n, int m){
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    int res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[j - 1] == s2[i - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(dp[i][j], res);
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return res;
}
