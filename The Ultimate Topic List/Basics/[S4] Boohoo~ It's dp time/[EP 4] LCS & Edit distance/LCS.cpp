#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m;
int recursion(int i, int j) {
    if (!i || !j) return 0;
    if (s[i - 1] == t[j - 1]) return 1 + recursion(i - 1, j - 1);
    int left = recursion(i - 1, j);
    int right = recursion(i, j - 1);
    return max(left, right);
}

void dpSolve() {
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string res;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) res += s[i - 1], i--, j--;
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
}


int main() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    dpSolve();
    return 0;
}
