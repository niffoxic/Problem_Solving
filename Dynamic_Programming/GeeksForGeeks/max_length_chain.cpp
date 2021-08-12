int maxChainLen(struct val p[], int n){
    int dp[n];
    for(int i = 0; i < n; i++) dp[i] = 1;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) v.pb({p[i].f, p[i].s});
    sort(v.begin(), v.end());
    int res = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (v[j].s < v[i].f)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    res = *max_element(dp, dp + n);
    return res;
}
