#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto & i : matrix)
            if (binary_search(i.begin(), i.end(), target)) return true;
        return false;
    }
};
