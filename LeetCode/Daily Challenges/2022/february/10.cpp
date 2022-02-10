

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        for(int num : nums)
        {
            sum += num;
            if (mp.find( k - sum) != mp.end())
                res += mp[k - sum];
            mp[sum]++;
        }
        return res;
    }
};
