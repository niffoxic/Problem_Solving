
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> res;
        for(auto i: nums){
            if (res.find(i) != res.end())
                return i;
            res.insert(i);
        }
        return 0;
    }
};
