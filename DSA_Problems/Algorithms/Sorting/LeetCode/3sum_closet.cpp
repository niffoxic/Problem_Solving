class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX - 1000;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int total = nums[left] + nums[right] + nums[i];
                if (abs(target - res) > abs(target - total)){
                    res = total;
                }
                if (total == target)
                    return total;
                else if (total > target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};
