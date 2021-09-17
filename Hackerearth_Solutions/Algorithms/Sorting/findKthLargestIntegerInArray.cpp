// Solution 1 thru sorting
class Solution {
    static bool comp(string& s1, string& s2){
        if (s1.length() == s2.length())
            return s1 > s2;
        return s1.length() > s2.length();
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[k - 1];
    }
};
