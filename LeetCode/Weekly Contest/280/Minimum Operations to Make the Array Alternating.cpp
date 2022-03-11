#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        unordered_map<int, int> mp1, mp2;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) mp1[nums[i]]++;
            else mp2[nums[i]]++;
        }
        vector<int> em1(2, 0), om1(2, 0), em2(2, 0), om2(2, 0);
        for (auto i: mp1) if (em1[1] <= i.second) { em1 = {i.first, i.second}; }
        mp1[em1[0]] = 0;
        for (auto i: mp1) if (em2[1] <= i.second) em2[0] = i.first, em2[1] = i.second;
        for (auto i: mp2) if (om1[1] <= i.second) om1 = {i.first, i.second};
        mp2[om1[0]] = 0;
        for (auto i: mp2) if (om2[1] <= i.second) om2[0] = i.first, om2[1] = i.second;
        if (em1[0] == om1[0]) return n - max(em1[1] + om2[1], em2[1] + om1[1]);
        return n - em1[1] - om1[1];
    }
};
