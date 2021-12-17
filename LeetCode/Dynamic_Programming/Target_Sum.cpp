// TARGET CAN BE 0 !!! WASTED MY 30 MINS !!

int findTargetSumWays(vector<int>& arr, int target){

    int sum = 0; for(int i : arr) sum += i;
    int setting = (sum + target) / 2;
    if (sum < target || target < -sum || ((sum + target) & 1)) return 0;
    int dp[arr.size() + 1][setting + 1];

    for(int i = 0; i <= setting; i++) dp[0][i] = 0;
    for(int i = 0; i <= arr.size(); i++) dp[i][0] = 1;

    for(int i = 1; i <= arr.size(); i++){
        for(int j = 0; j <= setting; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0) dp[i][j] += dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[arr.size()][setting];
}
