
#define pb push_back

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        using vi = vector<int>;
        vi neg, pos;
        for(auto i: nums){
            if (i > 0) pos.pb(i);
            else neg.pb(i);
        }
        int left = 0, right = 0, index = 0;
        for(int i = 0; i < (nums.size() >> 1); i++){
            nums[index] = pos[left], index++, left++;
            nums[index] = neg[right], right++, index++;
        }
        return nums;
    }
};
