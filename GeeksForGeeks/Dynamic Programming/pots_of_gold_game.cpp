int dp[501][501];
    int solving(vector<int>&arr, int i, int j){
        if (i > j) return 0;
        int left = 0, right = 0;
        if (dp[i][j] != -1) return dp[i][j];
        left = arr[i] + min(solving(arr, i + 2, j), solving(arr, i + 1, j - 1));
        right = arr[j] + min(solving(arr, i + 1, j - 1), solving(arr, i, j - 2));
        return dp[i][j] = max(left, right);
    }
    
    int maxCoins(vector<int>&arr,int n)
    {
        for(int i = 0; i <= 500; i++) for(int j = 0; j <= 500; j++) dp[i][j] = -1;
        return solving(arr, 0, n - 1);
    }
