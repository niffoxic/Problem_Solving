const int dp_size = 1e6;

int dp[dp_size][3];
int res(vvi &lists, int n, int last=-1){
    if (n == 0) return 0;
    if (dp[n][last] != -1) return dp[n][last];
    int sel_a = 0, sel_b = 0, sel_c = 0;
    if (last != 0)
        sel_a = lists[n - 1][0] + res(lists, n - 1, 0);
    if (last != 1)
        sel_b = lists[n - 1][1] + res(lists, n - 1, 1);
    if(last != 2)
        sel_c = lists[n - 1][2] + res(lists, n - 1, 2);
    return dp[n][last] = max(sel_a, max(sel_b, sel_c));
}


void solve(int case_no){
    int n; cin >> n;
    vvi vocation;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        vocation.pb({a, b, c});
    }
    for(auto &i: dp) for(auto &j: i) j = -1;
    print(res(vocation, n))

}
