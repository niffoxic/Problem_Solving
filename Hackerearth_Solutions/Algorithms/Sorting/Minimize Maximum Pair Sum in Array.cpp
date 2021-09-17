class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int res = INT_MIN;
        while(i < j){
            res = max(res, nums[j--] + nums[i++]);
        }
        return res;
    }
};
