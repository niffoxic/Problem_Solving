#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> res;
        for(int i = 0; i < plantTime.size(); i++)
            res.emplace_back(plantTime[i], growTime[i]);
        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>&b){
            return a.second > b.second;
        });
        int planting = 0, ans = 0;
        for(auto & re : res){
            planting += re.first;
            ans = max(ans, planting + re.second);
        }
        return ans;
    }
};
