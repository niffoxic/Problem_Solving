#include <bits/stdc++.h>
using namespace std;
#define template_size 1000009
using ll = long long;
int dp[template_size];
int mod = 1e9 + 7;
int solve(int n){
    if (!n) return dp[n] = 1;
    if (dp[n] != -1) return dp[n];
    int res = 0;
    for(int i = 1; i <= 6 && i <= n; i++){
        res += (solve(n - i) % mod);
        res %= mod;
    }
    return dp[n] = res;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++) dp[i] = -1;
    solve(n);
    cout << dp[n];
    return 0;
}
