#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(auto i: nums) st.insert(i);
        while (st.find(original) != st.end()) original <<= 1;
        return original;
    }
};
