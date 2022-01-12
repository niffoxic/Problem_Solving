#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, dp[4001], k; cin >> n;
    fill(dp + 1, dp + 4001, INT_MIN);
    while (cin >> k)
        for(int i = k; i <= n; i++)
            dp[i] = max(dp[i], dp[i - k] + 1);

    return cout << dp[n], 0;
}
