class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0, left = nums[1] - nums[0], pairs = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            if (nums[i + 1] - nums[i] == left) pairs++;
            else pairs = 0, left = nums[i + 1] - nums[i];
            res += pairs;
        }
        return res;
    }
};
