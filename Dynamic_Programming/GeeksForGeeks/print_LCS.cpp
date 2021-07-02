// DP SIMPLE BACKTRACKING I REALLY DONT WASTE MY 1 HOUR FIGURING IT OUT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void all_longest_common_subsequences(string s1, string s2, int n, int m){
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[j - 1] == s2[i - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << " ";
        }cout << nn;
    }
    print(nn)
    int i = m, j = n;
    string ans;
    while(i > 0 && j > 0){
        cout << dp[i][j] << " ";
        if (s2[i - 1] == s1[j - 1]){
            ans.push_back(s1[j - 1]);
            i--, j--;
        }else{
            if (dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }

    }
    print("")
    cout << ans << nn;
}
