class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        int left = 0, right = nums.size() - 1;

        while(left <= right){

            int mid = left + ((right- left) >> 1);

            if (!(mid & 1)){
                if (nums[mid] == nums[mid + 1]) left = mid + 1;
                else right = mid - 1;
            }else{
                if (nums[mid] == nums[mid - 1]) left = mid + 1;
                else right = mid - 1;

            }
        }
        return nums[left];
    }
};
