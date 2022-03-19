#include <bits/stdc++.h>
using namespace std;

#define template_size 5005
int n, m;
int arr[template_size], dp[template_size];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i]; double x; cin >> x;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) if (arr[j] <= arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    return cout << n - res, 0;
}
