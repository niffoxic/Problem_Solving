#include <bits/stdc++.h>
using namespace std;
const int maxW = 1e9;
const int maxV = 1e5;
const int maxN = 100;
int val[maxN + 1], wt[maxN + 1], n, w;
int dp[maxN + 1][maxV + 1];


void solve(){
    for(int i = 0; i <= n; i++) for(int j = 0; j <= maxV; j++) dp[i][j] = maxW + 1;
    dp[0][0] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = maxV; j >= 0; j--){
            dp[i][j] = dp[i - 1][j];
            if (j >= val[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - val[i]] + wt[i]);
            if (dp[i][j] <= w) res = max(res, j);
        }
    }
    cout << res;
}


int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> wt[i] >> val[i];
    solve();
    return 0;
}
