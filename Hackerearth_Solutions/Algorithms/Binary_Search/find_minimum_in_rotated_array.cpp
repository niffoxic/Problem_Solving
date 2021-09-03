class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        int left = 0, right = nums.size() - 1;
        int res = INT_MAX;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[left]){
                if (nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};
