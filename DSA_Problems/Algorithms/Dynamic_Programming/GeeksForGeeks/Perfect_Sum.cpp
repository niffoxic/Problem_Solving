int perfectSum(int arr[], int n, int sum) {

    int dp3[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp3[i][0] = 1;
    for (int i = 1; i <= sum; i++) dp3[0][i] = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                dp3[i][j] = (dp3[i - 1][j - arr[i - 1]] + dp3[i - 1][j]) % 1000000007;
            }
            else {
                dp3[i][j] = dp3[i - 1][j];
            }
        }
    }
    return dp3[n][sum];
}
