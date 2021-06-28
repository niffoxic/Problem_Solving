
// slow but it ll work :(
int dp[10000][100];

int solving(string s1, string s2, int n1, int n2, int i, int j){
    if (i == n1 || j == n2) return 0;

    if (dp[j][i] != -1) return dp[j][i];

    if (s1[i] == s2[j]){
        return dp[j][i] = 1 + solving(s1, s2, n1, n2, i + 1, j + 1);
    }

    int op1 = solving(s1, s2, n1, n2, i + 1, j);
    int op2 = solving(s1, s2, n1, n2, i, j + 1);

    return dp[j][i] = max(op1, op2);
}

bool isSubsequence(string s1, string s2) {
    for(auto & i : dp)
        for(int & j : i)
            j = -1;
    int n1 = s1.size();
    int n2 = s2.size();
    int res = solving(s1, s2, n1, n2, 0, 0);
    if (res == n1) return true;
    return false;
}
