class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) return {};
        int val = nums[0], last = nums[0];
        vector<string> res; bool isThere = false;
        for(int i = 1; i < nums.size(); i++){
            if (val + 1 != nums[i]){
                string ans = to_string(last);
                if (isThere) ans += "->", ans += to_string(nums[i - 1]);
                res.push_back(ans);
                isThere = false;
                val = nums[i];
                last = nums[i];
            }else isThere = true, val = nums[i];
        }
        string ans = to_string(last);
        if (isThere) ans += "->", ans += to_string(nums[nums.size() - 1]);
        res.push_back(ans);
        return res;
    }
};
