#include <bits/stdc++.h>
using namespace std;

#define template_size 5005
string s, t;
int dp[template_size][template_size];


int recursion(int n, int m) {
    if (!n || !m) return n ? n : m;
    int matched = s[n - 1] != t[m - 1];
    return min(min(recursion(n - 1, m) + 1, // deletion
                   recursion(n, m - 1) + 1), // add
               recursion(n - 1, m - 1) + matched); // replace
}


int dpImplementation(int n, int m) {
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = INT_MAX - 1000;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0) dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            if (j != 0) dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            if (i != 0 && j != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    return dp[n][m];
}


int main() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    cout << dpImplementation(n, m);
    return 0;
}
