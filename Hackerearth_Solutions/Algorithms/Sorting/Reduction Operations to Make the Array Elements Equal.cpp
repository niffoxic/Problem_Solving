
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res[50001] = {0};
        for(auto i: nums)
            res[i]++;
        int ans = 0, j = 0;
        for(int re : res){
            if (re){
                ans += re * j;
                j++;
            }
        }
        return ans;
    }
};
