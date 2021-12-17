int prefix[10001];


void dp()
{
    prefix[0] = 0;
    for (int i = 0; i < 10001; i++)
    {
        prefix[i] = (i & 1) + prefix[i / 2];
    }
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        dp();
        vector<pair<int, int>> res;
        for(auto i: arr){
            res.emplace_back(prefix[i], i);
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(auto i: res) ans.push_back(i.second);
        return ans;
    }
};
