#include <bits/stdc++.h>
using namespace std;
#define template_size 1000009
int dp[template_size], arr[template_size], n;


int solve(int cost){
    if (cost == 0) return dp[cost] = 0;
    if (dp[cost] != -1) return dp[cost];
    int res = 1 << 30;
    for(int i = 0; i < n; i++){
        if (arr[i] <= cost)
            res = min(res, solve(cost - arr[i]) + 1);
    }
    return dp[cost] = res;
}


int main(){
    int c; cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i <= c; i++) dp[i] = -1;
    solve(c);
    return cout << (dp[c] == (1 << 30)? -1: dp[c]), 0;
}
