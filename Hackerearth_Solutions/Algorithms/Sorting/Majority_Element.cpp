class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int index = 0;
        int counts = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[index]) counts++;
            else counts--;
            
            if (counts == 0){
                index = i;
                counts = 1;
            }
        }
        return nums[index];
    }
};
