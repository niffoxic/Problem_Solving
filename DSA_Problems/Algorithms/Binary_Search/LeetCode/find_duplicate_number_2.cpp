
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int current = abs(nums[i]);
            if (nums[current] < 0){
                return current;
            }
            nums[current] *= -1;
        }
        return -1;
    }
};
