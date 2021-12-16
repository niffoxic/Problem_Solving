class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;

        while(mid <= right){
            if (nums[mid] < 1){
                swap(nums[left], nums[mid]);
                left++, mid++;
            }else if (nums[mid] > 1){
                swap(nums[mid], nums[right]);
                right--;
            }else{
                mid++;
            }
        }
    }
};
