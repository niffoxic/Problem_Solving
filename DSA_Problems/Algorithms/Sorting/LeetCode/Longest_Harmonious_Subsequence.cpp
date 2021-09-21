class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> res;
        for(auto i: nums)
            res[i]++;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] - nums[i - 1] == 1){
                ans = max(ans, res[nums[i]] + res[nums[i - 1]]);
            }
        }
        return ans;
    }
};
