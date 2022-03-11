#include <bits/stdc++.h>

using namespace std;


class Solution {
public:


    int dp[20][1025][1025];

    int solve(vector<int> &nums, int index, int p1, int p2, int s) {
        if (index >= nums.size()) return 0;
        if (dp[index][p1][p2] != -1) return dp[index][p1][p2];
        int res = 0;
        for (int i = 1, temp; i <= s; i++) {
            if (((1 << i) & p1) == 0) {
                temp = p1;
                temp |= (1 << i);
                res = max(res, solve(nums, index + 1, temp, p2, s) + (nums[index] & i));
            } else if (((1 << i) & p2) == 0) {
                temp = p2;
                temp |= (1 << i);
                res = max(res, solve(nums, index + 1, p1, temp, s) + (nums[index] & i));
            }
        }

        return dp[index][p1][p2] = res;
    }


    int maximumANDSum(vector<int> &nums, int slots) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0, slots);
    }
};
