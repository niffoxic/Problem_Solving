#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> left, right;
        for(int i = 0; i < nums.size(); i++){
            if (i & 1) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end(), greater<>());
        int n = left.size(), m = right.size();
        int index = 0, l = 0, r = 0;
        while (l < n && r < m){
            if (!index || !(index & 1)) nums[index] = left[l], l++;
            else nums[index] = right[r], r++;
            index++;
        }
        while (l < n) nums[index] = left[l], l++, index++;
        while (r < m) nums[index] = right[r], r++, index++;
        return nums;
    }
};
