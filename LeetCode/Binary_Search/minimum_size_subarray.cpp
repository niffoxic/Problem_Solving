class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left_pin = 0, right_pin = 0, ans = INT_MAX, total = 0;
        while(left_pin < nums.size()){
            total += nums[right_pin];
            if (total >= target)
                ans = min(ans, right_pin - left_pin + 1);
            right_pin++;
            if (total >= target || right_pin >= nums.size()){
                total = 0;
                left_pin++;
                right_pin = left_pin;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};
