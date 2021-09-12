class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fs = INT_MIN, sd = INT_MIN;
        for(auto i: nums){
            if (fs < i){
                sd = fs;
                fs = i;
            }else if (sd < i){
                sd = i;
            }
        }
        return (fs - 1) * (sd - 1);
    }
};
