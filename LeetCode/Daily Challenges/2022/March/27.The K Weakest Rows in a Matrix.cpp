#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> res;
        for(int i = 0; i < mat.size(); i++){
            int current = 0;
            for(int j : mat[i]) current += j;
            res.emplace_back(current, i);
        }
        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b){
            if (a.first < b.first) return true;
            else if (a.first == b.first) return a.second < b.second;
            return false;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(res[i].second);
        return ans;
    }
};
