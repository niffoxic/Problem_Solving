// Solution 1 sorting and checking from left to till its not equal and right to left tills its not equal.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int>prefix(n);
        for(int i = 0; i < n; i++){
            prefix[i] = nums[i];
        }
        sort(prefix.begin(), prefix.end());
        int i = 0, j = n - 1;
        while(i < n){
            if (nums[i] != prefix[i])
                break;
            i++;
        }
        while(j >= 0){
            if (nums[j] != prefix[j])
                break;
            j--;
        }
        if (i == n) return 0;
        return j - i + 1;
    }
};

// Solution 2 same logic but thru finding the smallest position and largest postion same like we are doing in sorting
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
