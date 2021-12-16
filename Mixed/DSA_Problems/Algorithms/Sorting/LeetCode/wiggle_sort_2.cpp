class Solution {
public:

    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1, n = nums.size(), j = nums.size() - 1;
        vector<int>temp(nums);
        while(j >= 0){
            if (i >= n) i = 0;
            temp[i] = nums[j];
            j--, i += 2;
        }
        nums = temp;
    }
};
