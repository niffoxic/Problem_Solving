class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left >= nums.size() || nums[left] != target){
            return {-1, -1};
        }
        return {left, right - 1};
    }
};
