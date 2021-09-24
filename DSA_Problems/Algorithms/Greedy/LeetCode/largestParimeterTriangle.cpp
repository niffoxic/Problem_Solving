class Solution {
public:

    vector<int> otherTwo(vector<int>& nums, int selected_index){
        int left = 0, right = selected_index - 1;
        vector<int> res = {-1, -1};
        while (left < right){
            if (nums[left] + nums[right] > nums[selected_index]){
                res[0] = left, res[1] = right;
                left++;
            }else{
                left++;
            }
        }
        return res;
    }

    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 2; i--){
            vector<int> current = otherTwo(nums, i);
            if (current[0] != -1)
                return nums[i] + nums[current[0]] + nums[current[1]];
        }
        return 0;
    }
};
