#include <bits/stdc++.h>
using namespace std;

#if 0
    Hint - MCM (Matrix Chain Multiplication) Variant
#endif


class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums, int i, int j)
    {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = INT_MIN;
        for(int k = i; k < j; k++)
        {
            int current = 0;
            current += dp[i][k] != -1? dp[i][k]: solve(nums, i, k);
            current += dp[k + 1][j] != -1? dp[k + 1][j]: solve(nums, k + 1, j);
            current += nums[i - 1] * nums[k] * nums[j];
            res = max(res, current);
        }
        return dp[i][j] = res;
    }

    int maxCoins(vector<int>& nums) {
        nums.push_back(1); nums.insert(nums.begin(), 1);
        memset(dp, -1, sizeof(dp));
        return solve(nums, 1, nums.size() - 1);
    }
};
