#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 1, right = 1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1]) right = left + 1;
            else if (nums[i] < nums[i - 1]) left = right + 1;
        }
        return max(left, right);
    }
};
