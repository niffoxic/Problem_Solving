#include <bits/stdc++.h>
using namespace std;

#define template_size 5001
int dp[template_size][template_size];

int main(){
    int n, m; cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 2;
            else dp[i][j] = max(dp[i][j], max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
            res = max(res, dp[i][j]);
        }
    }
    return cout << res, 0;
}
