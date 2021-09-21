int res(int const arr[], int n){
    int dp[n + 1];
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int left = i == 2?INT_MAX: abs(arr[i] - arr[i - 2]) + dp[i - 2];
        int right = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        dp[i] = min(left, right);
    }
    return dp[n];
}

void solve(int case_no){
    int n; cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    print(res(arr, n))
}

int main()
{

    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    //cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
