int dp[501][501];

bool isPalindromic(string &s1, int i, int j){
    while (i < j){
        if (s1[i] != s1[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(string &s1, int i, int j){
    if (i >= j) return 0;
    if (isPalindromic(s1, i, j)) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int res = INT_MAX;
    for(int k = i; k < j; k++){
        int current = solve(s1, i, k) + solve(s1, k + 1, j) + 1;
        res = min(res, current);
    }

    return dp[i][j] = res;
}

int palindromicPartition(string &s1)
{
    for(int i = 0; i <= s1.length(); i++) for(int j = 0; j <= s1.length(); j++) dp[i][j] = -1;
    return solve(s1, 0, s1.length() - 1);
}
