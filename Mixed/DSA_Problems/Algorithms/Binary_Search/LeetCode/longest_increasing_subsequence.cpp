class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int current = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
            if (res.size() == current)
                res.push_back(nums[i]);
            else
                res[current] = nums[i];
        }
        return (int)res.size();
    }
};
