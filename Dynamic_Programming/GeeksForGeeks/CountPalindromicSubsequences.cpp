long long int  countPS(string s)
    {
        const int mod = 1e9+7;
       //Your code here
       int n = s.size();
       int dp[n][n]{};
       
       for(int i = n - 1; i >= 0; i--){
           dp[i][i] = 1;
           for(int j = i + 1; j < n; j++){
               dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod;
               if (s[i] == s[j]) dp[i][j]++;
               else
                dp[i][j] = (mod + dp[i][j] - dp[i + 1][j - 1]) % mod;
           }
       }
       return dp[0][n - 1];
    }
