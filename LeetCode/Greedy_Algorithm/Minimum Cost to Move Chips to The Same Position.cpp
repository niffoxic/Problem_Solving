class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int res = 0;
        for(auto i: pos) if (i & 1) res++;
        return min(res, (int)pos.size() - res);
    }
};
