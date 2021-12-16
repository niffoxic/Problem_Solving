class Solution {
public:

    bool canJump(vector<int>& nums) {
        int remaining = nums[0];
        if (!nums[0] && nums.size() > 1)
            return false;
        for(int i = 1; i < nums.size() - 1; i++){
            remaining = max(remaining - 1, nums[i]);
            if (!remaining)
                return false;
        }
        return true;
    }
};
