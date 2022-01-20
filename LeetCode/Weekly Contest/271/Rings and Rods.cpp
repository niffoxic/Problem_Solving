class Solution {
public:
    int countPoints(string& rings) {
        unordered_map<int, unordered_set<char>> res;
        for(int i = 0; i < rings.size(); i += 2)
            res[rings[i + 1] - '0'].insert(rings[i]);
        int ans = 0;
        for(auto &i: res)
            ans += i.second.size() == 3;
        return ans;
    }
};
