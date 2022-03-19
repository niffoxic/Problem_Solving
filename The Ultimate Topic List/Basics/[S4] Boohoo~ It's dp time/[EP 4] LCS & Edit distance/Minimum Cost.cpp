#include <bits/stdc++.h>
using namespace std;


string s, t;
#define template_size 1001
int dp[template_size][template_size];


int recursion(int n, int m){
    if (!n || !m) return n? n * 15: m * 30;
    if (dp[n][m] != -1) return dp[n][m];
    if (s[n - 1] == t[m - 1]) return dp[n][m] = recursion(n - 1, m - 1);
    return dp[n][m] = min(recursion(n - 1, m) + 15,
               recursion(n, m - 1) + 30);
}

void solve(){
    int n = s.size(), m = t.size();
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = -1;
    cout << recursion(n, m) << "\n";
}

int main(){
    while (true){
        cin >> s; if (s == "#") break;
        cin >> t;
        solve();
    }
    return 0;
}
