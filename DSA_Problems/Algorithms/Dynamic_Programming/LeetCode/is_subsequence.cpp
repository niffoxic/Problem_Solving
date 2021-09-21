
// slow but it ll work :(
// arr[10^4][100] is faster than arr[100][10^4]

int dp[10000][100];

int solving(string s1, string s2, int n1, int n2, int i, int j){
    if (i == n1 || j == n2) return 0;
    if (dp[j][i] != -1) return dp[j][i];

    if (s1[i] == s2[j]) return dp[j][i] = 1 + solving(s1, s2, n1, n2, i + 1, j + 1);
    return dp[j][i] = max(solving(s1, s2, n1, n2, i + 1, j), solving(s1, s2, n1, n2, i, j + 1));
}

bool isSubsequence(string s1, string s2) {
    for(auto & i : dp) for(int & j : i) j = -1;
    int n1 = s1.size(), n2 = s2.size();
    int res = solving(s1, s2, n1, n2, 0, 0);
    return res == n1;
}
