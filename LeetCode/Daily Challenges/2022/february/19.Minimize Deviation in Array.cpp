#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(auto i: nums) st.insert((i & 1)? i * 2: i);
        int res = *st.rbegin() - *st.begin();
        while (!(*st.rbegin() & 1))
        {
            int currentMax = *st.rbegin();
            st.erase(currentMax);
            st.insert(currentMax >> 1);
            res = max(res, *st.rbegin() - *st.begin());
        }
        return res;
    }
};


