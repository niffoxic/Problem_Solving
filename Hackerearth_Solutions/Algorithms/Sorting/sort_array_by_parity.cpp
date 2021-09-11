class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = -1, j = nums.size() - 1;
        
        while(i < j){
            if (nums[j] % 2 == 0){
                i++;
                swap(nums[i], nums[j]);
            }else{
                j--;
            }
        }
        return nums;
    }
};
