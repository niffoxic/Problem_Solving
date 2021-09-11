class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int, int>> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(make_pair(nums[i], i));
        }
        sort(res.begin(), res.end());
        if (nums.size() == 1) return 0;
        return ((res[res.size() - 2].first * 2) <= res[res.size() - 1].first)?res[res.size() - 1].second:-1;
    }
};
