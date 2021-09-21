int dp[1001][1001];
int solve(string t, vector<string> &s, int i, int j){
    if(find(s.begin(), s.end(), t.substr(i, (j-i+1))) != s.end())
        return 1;
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
        
    for(int k=i; k<j; k++){
        if(solve(t, s, i, k) && solve(t, s, k+1, j))
            return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    memset(dp, -1, sizeof(dp));
    return solve(A, B, 0, A.size()-1);
}
