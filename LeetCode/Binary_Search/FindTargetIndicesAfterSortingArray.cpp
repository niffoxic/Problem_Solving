#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        for(int num : nums){
            if (num == target)
                mid++;
            if (num < target)
                left++;
        }
        vector<int> res;
        int i = 0;
        while (i < mid){
            res.push_back(left);
            left++, i++;
        }
        return res;

    }
};
