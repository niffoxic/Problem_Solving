class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();

        if (n <= 1) return 0;

        for(int i = 0; i < n; i++){
            if (i == 0 && nums[i] > nums[i + 1]){
                mini = nums[i];
                maxi = nums[i];
            }
            else if (i == n - 1 && nums[i] < nums[i - 1]){
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            }

            if ((i > 0 && nums[i] < nums[i - 1]) || (i < n - 1 && nums[i] > nums[i + 1])){
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            }
        }

        if (mini == INT_MAX && maxi == INT_MIN) return 0;
        int left = -1, right = -1;

        for(int i = 0; i < n; i++){
            if (i == 0 && nums[i] > mini){
                left = i;
                break;
            } if (i > 0 && nums[i] > mini){
                left = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if (i == n - 1 && nums[i] < maxi){
                right = i;
                break;
            }
            if (i < n - 1 && nums[i] < maxi){
                right = i;
                break;
            }
        }
        return right - left + 1;
    }
};
