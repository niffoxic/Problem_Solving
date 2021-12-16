class Solution {

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> res;
        for(const auto& i: words) res[i]++;
        set<pair<int, string>> set_res;
        for(const auto& i: res)
            set_res.insert({(-1) * i.second, i.first});
        vector<string> ans;
        for(const auto& i: set_res){
            if (k--) ans.push_back(i.second); else break;
        }
        return ans;
    }
};
