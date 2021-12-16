class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1;

        while(even < nums.size() && odd < nums.size()){
            if (nums[odd] % 2 == 0){
                swap(nums[odd], nums[even]);
                even += 2;
            }else if (nums[even] % 2 == 1){
                swap(nums[odd], nums[even]);
                odd += 2;
            }else{
                even += 2;
                odd += 2;
            }
        }
        return nums;
    }
};
