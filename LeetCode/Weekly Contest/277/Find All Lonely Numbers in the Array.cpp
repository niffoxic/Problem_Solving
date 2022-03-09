class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;
        vector<int> res;
        for(auto i: nums){
            if (mp[i] == 1 && (
                    mp.find(i + 1) == mp.end() &&
                    mp.find(i - 1) == mp.end()
                    )) res.push_back(i);
        }
        return res;
    }
};
