#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (!obstacleGrid[i - 1][j - 1]){
                    if (i == 1 && j == 1) dp[i][j] = 1;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
