#include <bits/stdc++.h>
using namespace std;
#define template_size 100009
using ll = long long;
ll arr[template_size], dp[template_size], n;
const ll inf = 1e18;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i <= n; i++) dp[i] = inf;
    dp[0] = 0, dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = abs(arr[i - 1] - arr[i - 2]) + dp[i - 1];
        if (i > 2) dp[i] = min(dp[i], abs(arr[i - 1] - arr[i - 3]) + dp[i - 2]);
    }
    return cout << dp[n], 0;
}
