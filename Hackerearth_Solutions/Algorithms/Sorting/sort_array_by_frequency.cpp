class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> res;
        for(auto i: nums) {
            res[i]++;
        }
        
        vector<pair<int, int>> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end(), comp);
        vector<int> fnl;
        for(auto i : ans) {
            while(i.second--)
                fnl.push_back(i.first);
        }
        return fnl;
	}
};
