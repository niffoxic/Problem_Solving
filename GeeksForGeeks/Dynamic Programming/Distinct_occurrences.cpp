const int mod = 1e9+7;

int dp[8001][101];
int solveSubsequenceCount(string &s1, string &s2, int i=0, int j=0)
{
    if (j == s2.size()) return 1;
    if (i == s1.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int left = 0, right = 0;
    if (s1[i] == s2[j]) left =  solveSubsequenceCount(s1, s2, i + 1, j + 1);
    right =  solveSubsequenceCount(s1, s2, i + 1, j);
    return dp[i][j] = (left + right) % mod;
}
int subsequenceCount_rec(string &s1, string &s2){
    for(auto & i : dp) for(int & j : i) j = -1;
    return solveSubsequenceCount(s1, s2);
}

int subsequenceCount_dp(string &s1, string &s2){
    int m = s1.size(), n = s2.size();
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++)
        dp[i][0] = 1;
    for(int j = 1; j <= n; j++)
        dp[0][j] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[m - i] == s2[n - j])
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][n];
}
