#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll const mod = 1e9 + 7;
ll inverse_mod = 500000004;

int main(){
    ll n; cin >> n;
    ll val = (n * (n + 1)) >> 1;
    if (val & 1) return cout << 0, 0;
    ll half = val >> 1;
    ll dp[half + 1];
    for(int i = 0; i <= half; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) for(ll j = half; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % mod;
    cout << (inverse_mod * dp[half]) % mod;
    return 0;
}
