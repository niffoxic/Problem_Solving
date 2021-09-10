// Solution 1 using Bitwise operator
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i <= nums.size(); i++) res ^= i;
        for(auto i: nums) res ^= i;
        return res;
    }
};

// Solution 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = (n * (n + 1)) / 2;
        for(auto i: nums) res -= i;
        return res;
    }
};
