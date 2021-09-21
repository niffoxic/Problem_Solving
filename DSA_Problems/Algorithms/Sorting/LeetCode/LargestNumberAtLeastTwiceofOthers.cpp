class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0, index1 = -1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[index] < nums[i]){
                index1 = index;
                index = i;
            }else if (index1 == -1 || nums[index1] < nums[i]){
                index1 = i;
            }
        }
        if (index1 == -1) return index;
        return nums[index1] * 2 <= nums[index]?index:-1;
    }
};
