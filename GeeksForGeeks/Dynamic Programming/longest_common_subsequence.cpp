
// Recursive solution
int dp[1001][1001];
int lcsSolve(int x, int y, string s1, string s2)
{
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0 || y == 0) return 0;
    if (s1[x - 1] == s2[y - 1]) return dp[x][y] = 1 + lcsSolve(x - 1, y - 1, s1, s2);
    int left = lcsSolve(x - 1, y, s1, s2);
    int right = lcsSolve(x, y - 1, s1, s2);

    return dp[x][y] = max(left, right);
}

// DP solution
int lcs(int x, int y, string s1, string s2){
    for(int i = 0; i <= x; i++) dp[i][0] = 0;
    for(int i = 0; i <= y; i++) dp[0][i] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}
