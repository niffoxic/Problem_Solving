#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        int n = nums.size();
        vector<pair<int, int>> prefix(n, {0, 0});
        prefix[0] = (nums[0] == 0 ? make_pair(1, 0) : make_pair(0, 1));
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1];
            if (nums[i] == 1) prefix[i].second++;
            else prefix[i].first++;
        }
        vector<int> res;
        long mx = 0;
        for (int i = 0; i <= n; ++i) {
            int score = 0;
            if (i > 0) score += prefix[i - 1].first;
            if (i < n) score += prefix.back().second - (i > 0 ? prefix[i - 1].second : 0);
            if (score > mx) mx = score, res = {i};
            else if (score == mx) res.emplace_back(i);
        }
        return res;
    }
};
