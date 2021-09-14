class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int left = j + 1, right = n - 1, remain = target - nums[i] - nums[j];
                while(left < right){
                    if (nums[left] + nums[right] < remain)
                        left++;
                    else if (nums[left] + nums[right] > remain)
                        right--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int temp_left = nums[left], temp_right = nums[right];
                        while (left < right && nums[left] == temp_left)
                            left++;
                        while(right > left && temp_right == nums[right])
                            right--;
                    }
                }
                while(j + 1 < n && nums[j] == nums[j + 1])
                    j++;
                while (i + 1 < n && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return ans;
    }
};
