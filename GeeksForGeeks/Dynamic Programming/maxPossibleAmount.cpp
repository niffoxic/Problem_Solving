class Solution{
public:
    int dp[1001][1001];

    int recursion(int arr[], int i, int j){
        if (i > j)
            return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = arr[i] + min(recursion(arr, i + 1, j - 1),
                                recursion(arr, i + 2, j));
        int right = arr[j] + min(recursion(arr, i + 1, j - 1),
                                 recursion(arr, i, j - 2));
        return dp[i][j] = max(left, right);
    }

    int maxAmount(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return recursion(arr, 0, n - 1);
    }
};
