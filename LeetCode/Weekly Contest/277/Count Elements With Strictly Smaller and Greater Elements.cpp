class Solution {
public:
    int countElements(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int ma = *max_element(nums.begin(), nums.end());
        int res = 0;
        for(auto i: nums) if (i > mi && i < ma) res++;
        return res;
    }
};
