class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        using vi = vector<int>;
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vi& a, vi& b){
            return a[1] < b[1];
        });
        int res = 1, last = pairs[0][1];
        for(int i = 1; i < n; i++){
            if (pairs[i][0] > last) last = pairs[i][1], res++;
        }
        return res;
    }
};
