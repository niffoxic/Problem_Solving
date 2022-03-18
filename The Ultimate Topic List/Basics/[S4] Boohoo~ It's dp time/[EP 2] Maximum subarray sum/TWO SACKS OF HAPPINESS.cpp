#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n; cin >> n;
    ll arr[n], left[n], right[n], dp[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        left[i] = arr[i];
        if (i > 0) left[i] = max(left[i], left[i - 1] + arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) right[i] = max(arr[i], right[i + 1] + arr[i]);
    dp[n - 1] = INT_MIN;
    for(int i = n - 2; i >= 0; i--) dp[i] = max(dp[i + 1], right[i + 1]);
    ll res = INT_MIN;
    for(int i = 0; i < n; i++) res = max(res, dp[i] + left[i]);
    return cout << res, 0;
}
