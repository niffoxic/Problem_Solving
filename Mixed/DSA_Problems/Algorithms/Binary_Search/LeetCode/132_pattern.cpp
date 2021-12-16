class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        set<int> right;
        vector<int> left(nums.size() + 1);
        left[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            left[i] = min(left[i - 1], nums[i]);
        right.insert(nums[nums.size() - 1]);
        for(int i = nums.size() - 2; i >= 1; i--){
            if (nums[i] > left[i - 1]){
                auto rhs = right.upper_bound(left[i - 1]);
                if (rhs != right.end()){
                    if (*rhs < nums[i]){
                        return true;}
                }
            }
            right.insert(nums[i]);
        }
        return false;
    }
};
