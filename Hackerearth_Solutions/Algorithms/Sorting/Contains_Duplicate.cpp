
// Solution 1 - Using HashMap O(N) time + O(N) space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>res;
        for(auto i: nums){
            if (res.find(i) != res.end()) return true;
            res[i]++;
        }
        return false;
    }
};

// Solution 2- using sorting O(NLOGN) time + O(1) space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};
