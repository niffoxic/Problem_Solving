class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i++){
            int left = 0, right = i - 1;
            while(left < right){
                if (nums[left] + nums[right] > nums[i]){
                    res += right - left;
                    right--;
                }else left++;
            }
        }
        return res;
    }
};
