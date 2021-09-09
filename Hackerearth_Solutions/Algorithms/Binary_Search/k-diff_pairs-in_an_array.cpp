class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> res;
        int ans = 0;
        for(int & num : nums){
            if (res.count(num + k) && res.count(num) == 0)
                ans++;
            if (res.count(num - k) && res.count(num) == 0)
                ans++;
            res[num]++;
        }
        if (k == 0){
            for(auto i: res){
                if (i.second >= 2)
                    ans++;
            }
        }
        return ans;
    }
};
