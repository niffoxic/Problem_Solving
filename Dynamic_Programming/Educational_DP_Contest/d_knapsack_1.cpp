ll recursion(vll &value, vll &weight, ll n, ll w){
    if (n == 0 || w == 0)
        return 0LL;
    ll left = 0LL, right = 0LL;
    if (w >= weight[n - 1]){
        left = value[n - 1] + knapsack_1(value, weight, n - 1LL, w - weight[n - 1]);
    }
    right = knapsack_1(value, weight, n - 1LL, w);
    return max(left, right);
}

ll knapsack(vll &value, vll &weight, ll n, ll w){
    ll dp[n + 1][w + 1];
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= w; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= w; j++){
            if (j >= weight[i - 1]){
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

void solve(int case_no){
    int n, w;
    cin >> n >> w;
    vll val; vll weigh;
    for(int i = 0; i < n; i++){
        ll ft, sd; cin >> ft >> sd;
        weigh.pb(ft);
        val.pb(sd);
    }
    cout << knapsack(val, weigh, n, w) << nn;
}
