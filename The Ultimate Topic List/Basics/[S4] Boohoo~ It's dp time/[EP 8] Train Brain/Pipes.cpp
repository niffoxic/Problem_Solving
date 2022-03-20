#include <bits/stdc++.h>
using namespace std;

#define template_size 200005
int arr[template_size][2], dp[template_size][2];


void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c - '0' > 2) arr[i][0] = 2;
        else arr[i][0] = 1;
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c - '0' > 2) arr[i][1] = 2;
        else arr[i][1] = 1;
        dp[i][1] = 1;
    }
    dp[0][0] = 1, dp[n][1] = 0, dp[n][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i][0] == 1 && dp[i - 1][0]) dp[i][0] = 1;
        else if (arr[i][0] == 2 && arr[i][1] == 2 && dp[i - 1][1]) dp[i][0] = 1;
        else dp[i][0] = 0;
        if (arr[i][1] == 1 && dp[i - 1][1]) dp[i][1] = 1;
        else if (arr[i][1] == 2 && arr[i][0] == 2 && dp[i - 1][0]) dp[i][1] = 1;
        else dp[i][1] = 0;
    }
    cout << (dp[n][1]? "YES": "NO") << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
