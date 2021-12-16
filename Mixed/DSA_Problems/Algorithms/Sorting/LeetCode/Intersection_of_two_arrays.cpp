#define pb push_back
#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *search, *other;
            ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
        sort(all(nums1)), sort(all(nums2));
        if (nums1.size() > nums2.size()){
            search = &nums1;
            other = &nums2;
        }else {
            search = &nums2;
            other = &nums1;
        }
        unordered_set<int>res;
        for(auto i:*search){
            if (binary_search(other->begin(), other->end(), i)) res.insert(i);
        }
        vector<int>ans;
        for(auto i: res) ans.pb(i);
        return ans;
    }
};
