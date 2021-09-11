class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(k){
            nums[i] *= -1;
            k--;
            if (i + 1 < nums.size() && nums[i] > nums[i + 1]){
                i++;
            }
        }
        int res = 0;
        for(auto i: nums) res += i;
        return res;
    }
};
