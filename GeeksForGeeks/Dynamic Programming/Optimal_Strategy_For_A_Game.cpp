using ll = long long;

ll dp[1001][1001];

// ----------------------------------Optimal Strategy For a Game----------------TOP BOTTOM DP------------------------------
ll maximumAmountSolve(int arr[], int n, int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int left = arr[i] + min(maximumAmountSolve(arr, n, i + 2, j), maximumAmountSolve(arr, n, i + 1, j - 1));
    int right = arr[j] + min(maximumAmountSolve(arr, n, i, j - 2), maximumAmountSolve(arr, n, i + 1, j - 1));

    return dp[i][j] = max(left, right);
}

ll maximumAmount(int arr[], int n) {
    for (auto& i : dp) for (auto &j : i) j = -1;
    return maximumAmountSolve(arr, n, 0, n - 1);
}
