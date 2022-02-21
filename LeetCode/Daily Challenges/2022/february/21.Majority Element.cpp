
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], counts = 1;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] == res) counts++;
            else counts--;
            if (counts <= 0) res = nums[i], counts = 1;
        }
        return res;
    }
};
