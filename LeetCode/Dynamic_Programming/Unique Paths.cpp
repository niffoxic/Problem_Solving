#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int recursion(int m, int n, vector<vector<int>>& dp){
        if (!m && !n) return 1;
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        int left = recursion(m - 1, n, dp);
        int right = recursion(m, n - 1, dp);
        return dp[m][n] = left + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursion(m - 1, n - 1, dp);
    }
};
