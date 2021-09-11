class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> res;
        for(auto i: heights){
            res.push_back(i);
        }
        sort(res.begin(), res.end());
        int ans = 0;
        for(int i = 0; i < heights.size(); i++)
            if (heights[i] != res[i]) ans++;
        return ans;
    }
};
