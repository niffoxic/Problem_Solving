#include <bits/stdc++.h>
using namespace std;
const int template_size = 1e6 + 10;
int dp[template_size], n, c;
const int mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = 1;
    for(auto i: arr) for(int j = i; j <= c; j++) dp[j] = (dp[j] + dp[j - i]) % mod;
    return cout << dp[c], 0;
}
