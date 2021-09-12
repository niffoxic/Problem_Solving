class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx[2] = {INT_MIN, INT_MIN};
        int mn[2] = {INT_MAX, INT_MAX};
        
        for(auto i: nums){
            if (i > mx[0]){
                mx[1] = mx[0];
                mx[0] = i;
            }else if (i > mx[1]){
                mx[1] = i;
            }
            
            if (i < mn[0]){
                mn[1] = mn[0];
                mn[0] = i;
            }else if (i < mn[1]){
                mn[1] = i;
            }
        }
        return mx[0] * mx[1] - mn[0] * mn[1];
    }
};
