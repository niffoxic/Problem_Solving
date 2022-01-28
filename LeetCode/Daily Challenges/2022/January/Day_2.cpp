#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mp[60] = {0};
        int res = 0;
        for(int i : time)
        {
            res += mp[(60 - (i % 60)) % 60];
            mp[i % 60]++;
        }
        return res;
    }
};
