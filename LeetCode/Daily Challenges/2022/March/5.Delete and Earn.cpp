#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        int n = 10001;
        if (nums.size() == 1) return nums[0];
        vector<int> mp(n, 0);
        for (auto &i: nums) mp[i] += i;
        int left = mp[0];
        int right = max(left, mp[1]);
        for (int i = 2; i < n; i++) {
            int cur = max(right, left + mp[i]);
            left = right;
            right = cur;
        }
        return max(left, right);
    }
};
