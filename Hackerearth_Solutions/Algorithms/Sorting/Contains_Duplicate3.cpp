class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0) return false;
        multiset<long> res;
        for(int i = 0; i < nums.size(); i++){
            if (i > k) res.erase(nums[i - k - 1]);
            auto left = res.lower_bound((long)nums[i] - t);
            if (left != res.end() && *left <= (long)nums[i] + t) return true;
            res.insert(nums[i]);
        }
        return false;
    }
};
