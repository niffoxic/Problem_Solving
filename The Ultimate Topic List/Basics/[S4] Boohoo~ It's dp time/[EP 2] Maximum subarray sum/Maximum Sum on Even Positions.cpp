#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    int n; cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(3));
    for(int i = 0; i < n; i++){
        dp[i + 1][0] = dp[i][0] + (i & 1? 0: arr[i]);
        if (i + 2 <= n) dp[i + 2][1] = max(dp[i][1], dp[i][0]) + (i & 1? arr[i]: arr[i + 1]);
        dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1? 0: arr[i]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
