class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0; for(auto i: nums) total += i;
        vector<int> res;
        int current = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            current += nums[i];
            res.push_back(nums[i]);
            if (current > total - current)
                return res;
        }
        return res;
    }
};
