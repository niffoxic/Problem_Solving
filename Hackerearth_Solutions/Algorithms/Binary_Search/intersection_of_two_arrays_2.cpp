class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        umi res;
        vi ans;
        for(int & i : nums1)
            res[i]++;
        for(int & i: nums2){
            if (res[i]){
                res[i]--;
                ans.pb(i);
            }
        }
        return ans;
    }
};
