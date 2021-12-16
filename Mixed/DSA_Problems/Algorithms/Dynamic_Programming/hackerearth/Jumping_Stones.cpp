#include <bits/stdc++.h>

int jumping(int n, int k, int dp[]){
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int res = 0;
    for(int i = 1; i <= k; i++){
        if (i <= n - 1){
            res += jumping(n - i, k, dp);
            res %= mod;
        }
    }
    return dp[n] = res;
}

int jumping_bottom_up(int n, int k, int dp[]){
    for(int i = 0; i <= n; i++) dp[i] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if (i >= j){
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    return dp[n];
}
