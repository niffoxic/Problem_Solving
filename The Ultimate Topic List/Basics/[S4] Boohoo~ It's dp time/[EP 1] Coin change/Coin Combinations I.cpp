#include <bits/stdc++.h>
using namespace std;
const int template_size = 1e6 + 10;
using ll = int;
ll dp[template_size], n;
const ll mod = 1e9 + 7;

ll solve(vector<int>& arr, ll cost){
    if (cost < 0) return 0;
    if (dp[cost] != -1) return dp[cost];
    dp[cost] = 0;
    for(int i = 0; i < n && arr[i] <= cost; i++)
        dp[cost] = (dp[cost] + solve(arr, cost - arr[i])) % mod;
    return dp[cost];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    ll c; cin >> n >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    dp[0] = 1;
    return cout << solve(arr, c), 0;
}
