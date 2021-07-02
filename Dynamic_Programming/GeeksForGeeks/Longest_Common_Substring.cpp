// DP

int longestCommonSubstr(string s1, string s2, int n, int m){
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    int res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[j - 1] == s2[i - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(dp[i][j], res);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}
