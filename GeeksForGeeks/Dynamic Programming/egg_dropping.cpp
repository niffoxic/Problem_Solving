int dp[201][201];
// Matrix chain multiplication aka MCM

int solving(int egg, int floor){
    if (floor == 0 || floor == 1) return floor;
    if (egg == 1) return floor;
    if (dp[egg][floor] != -1) return dp[egg][floor];
    int mn = INT_MAX;
    for(int k = 1; k <= floor; k++){
        int temp = 1 + max(solving(egg - 1, k - 1),
                           solving(egg, floor - k));
        mn = min(mn, temp);
    }
    return dp[egg][floor] = mn;
}

int eggDrop(int n, int k)
{
    for(int i = 0; i <= 200; i++) for(int j = 0; j <= 200; j++) dp[i][j] = -1;
    return solving(n, k);
}
