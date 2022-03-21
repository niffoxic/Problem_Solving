#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int recursion(vector<int>& nums, int index, vector<int>& dp){
        if (index >= nums.size()) return INT_MAX - 1000;
        if (index == nums.size() - 1) return 0;
        if (dp[index] != -1) return dp[index];
        int res = INT_MAX - 1000;
        for(int i = 1; i <= nums[index]; i++) res = min(res, 1 + recursion(nums, index + i, dp));
        return dp[index] = res;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recursion(nums, 0, dp);
    }
};
