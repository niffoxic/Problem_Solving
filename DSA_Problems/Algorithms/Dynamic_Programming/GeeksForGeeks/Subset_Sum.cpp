// Subset Sum Problem
int dp2[101][10001];
bool isSubsetSumSolve(int n, int arr[], int sum, int index) {     // Recursive sol
    if (sum == 0) {
        return true;
    }
    if (index == n || sum < 0) return false;
    return (isSubsetSumSolve(n, arr, sum - arr[index], index + 1) || isSubsetSumSolve(n, arr, sum, index + 1));
}

bool isSubsetSum(int n, int arr[], int sum) {     // DP solution
    for (int i = 0; i < 10001; i++) dp2[0][i] = 0;
    for (int i = 0; i < 100; i++) dp2[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                dp2[i][j] = dp2[i - 1][j - arr[i - 1]] || dp2[i - 1][j];
            }
            else {
                dp2[i][j] = dp2[i - 1][j];
            }
        }
    }
    return dp2[n][sum];
}
