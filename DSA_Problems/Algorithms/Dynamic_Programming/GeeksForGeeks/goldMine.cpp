class Solution {
public:

    int getMaximumGold(vector<vector<int>>& cave) {
        int n = cave.size(), m = cave[0].size();
        int dp[n][m];
        int res = 0;
        for (int j = m - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                if (j == m - 1) {
                    dp[i][j] = cave[i][j];
                }
                else if (i == 0) {
                    dp[i][j] = cave[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
                }
                else if (i == n - 1) {
                    dp[i][j] = cave[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
                }
                else {
                    dp[i][j] = cave[i][j] + max(dp[i - 1][j + 1], max(dp[i + 1][j + 1], dp[i][j + 1]));
                }
                res = max(res, dp[i][j]);
            }

        }
        return res;
    }
};
