

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int cap = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            if (nums[i] != nums[cap]){
                cap++;
                nums[cap] = nums[i];
            }
        }
        return cap + 1;
    }
};
