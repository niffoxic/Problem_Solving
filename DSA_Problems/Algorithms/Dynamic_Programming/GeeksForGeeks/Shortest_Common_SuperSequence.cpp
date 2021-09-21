// DP    

int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
    
        int res = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if (x[i - 1] == y[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res += dp[i][j];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (m + n) - dp[m][n];
    }
