class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int i = 0, j = 0;
        
        while(i < g.size() && j < s.size()){
            if (g[i] <= s[j]){
                res++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return res;
    }
};
