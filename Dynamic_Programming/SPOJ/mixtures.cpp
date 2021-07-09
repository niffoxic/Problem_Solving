// Link -> https://www.spoj.com/problems/MIXTURES/

#define nn "\n"
#define print(x) cout << x << nn;
using ll = long long;

int arr[1000];
ll dp[1000][1000];

ll sum(int i, int j){
    ll res = 0;
    for(int k = i; k <= j; k++){
        res += arr[k];
        res %= 100;
    }
    return res;
}

ll solveMixtures(int i, int j){
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = LONG_LONG_MAX;
    for(int k = i; k <= j; k++){
        dp[i][j] = min(dp[i][j], solveMixtures(i, k) + solveMixtures(k + 1, j) + (sum(i, k) * sum(k + 1, j)));
    }
    return dp[i][j];
}


int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int n;
    while(cin >> n){
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = -1;
        for(int i = 0; i < n; i++) cin >> arr[i];
        print(solveMixtures(0, n - 1))
    }

  
    return 0;
}
