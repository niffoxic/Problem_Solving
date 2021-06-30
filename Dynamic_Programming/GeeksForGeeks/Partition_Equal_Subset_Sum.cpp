// Partition Equal Subset Sum

// Recursion
bool equalPartitionSolve(int n, int arr[], int sum, int current) {
    if (n == 0 || sum < 0 || current > sum) return false;
    if (sum == current) return true;

    return equalPartitionSolve(n - 1, arr, sum - arr[n - 1], current + arr[n - 1]) ||
        equalPartitionSolve(n - 1, arr, sum, current);
}


bool dp3[101][10001];

bool equalPartition(int n, int arr[])
{
    int sum = 0; for (int i = 0; i < n; i++) sum += arr[i];
    if (sum & 1) return false;
    sum /= 2;

    for (int i = 0; i < sum + 1; i++) dp3[0][i] = false;
    for (int i = 0; i < n + 1; i++) dp3[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                dp3[i][j] = dp3[i - 1][j - arr[i - 1]] || dp3[i - 1][j];
            }
            else {
                dp3[i][j] = dp3[i - 1][j];
            }
        }
    }
    return dp3[n][sum];
}
