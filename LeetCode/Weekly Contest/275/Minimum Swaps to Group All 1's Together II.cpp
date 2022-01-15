class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, n = nums.size();
        for(auto i: nums)
            if (i == 1) ones++;
        int res = n, i = 0, j = 0, current = 0;
        nums.insert(nums.end(), nums.begin(), nums.end());
        while (j < 2 * n){
            current += nums[j] == 1;
            if (j - i + 1 == ones){
                res = min(res, ones - current);
                current -= nums[i] == 1;
                i++;
            }
            j++;
        }
        return res == n?0: res;
    }
};
