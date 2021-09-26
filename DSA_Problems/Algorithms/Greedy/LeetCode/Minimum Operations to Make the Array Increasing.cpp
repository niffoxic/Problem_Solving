class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] <= nums[i - 1]){
                int current = abs(nums[i] - nums[i - 1]) + 1;
                res += current;
                nums[i] += current;
            }
        }
        return res;
    }
};
