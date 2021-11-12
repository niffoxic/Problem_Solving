class Solution {
public:

    int recursion(int amt, vector<int>& coins, int n){
        if (n == 0 && amt != 0)
            return 0;
        if (amt == 0)
            return 1;
        int left = 0, right = 0;
        if (coins[n - 1] <= amt)
        {
            left = recursion(amt - coins[n - 1], coins, n);
        }
        right = recursion(amt, coins, n - 1);
        return left + right;
    }

    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        int dp[n + 1][amt + 1];

        for(int j = 1; j <= amt; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amt; j++){
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j)
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amt];
    }
};
