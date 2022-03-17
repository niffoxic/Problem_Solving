#include <bits/stdc++.h>
using namespace std;
#define template_size 100009
using ll = long long;
ll arr[template_size], dp[template_size], n, k;
const ll inf = 1e18;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 0, dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = inf;
        for(int j = 1; j <= k && i > j; j++)
            dp[i] = min(dp[i], abs(arr[i] - arr[i - j]) + dp[i - j]);
    }
    return cout << dp[n], 0;
}
