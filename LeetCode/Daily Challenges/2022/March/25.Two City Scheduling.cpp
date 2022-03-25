#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return a[0] - a[1] < b[0] - b[1];
        });
        int res = 0, n = costs.size() >> 1;
        for(int i = 0; i < n; i++) res += costs[i][0] + costs[i + n][1];
        return res;
    }
};
