class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int left = -1, n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                left = i - 1;
                break;
            }
        }
        if (left == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        int at = left + 1;
        for (int i = left + 1; i < n; i++) {
            if (nums[i] <= nums[left]) break;
            at = nums[i] <= nums[at] ? i : at;
        }
        swap(nums[left], nums[at]);
        reverse(begin(nums) + left + 1, end(nums));
    }
};
