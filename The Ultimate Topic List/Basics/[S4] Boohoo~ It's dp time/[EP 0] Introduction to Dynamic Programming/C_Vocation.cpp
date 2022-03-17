#include <bits/stdc++.h>
using namespace std;
#define template_size 100009
using ll = long long;
ll n, arr[template_size][3], dp[template_size][3];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for(int i = 1; i <= n; i++){
        dp[i][0] = arr[i - 1][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i - 1][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i - 1][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }
    return cout << max(dp[n][0], max(dp[n][1], dp[n][2])), 0;
}
