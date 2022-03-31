class Solution {
public:
int splitArray(vector<int> &nums, int m) {
    int left = 0, right = 0, n = nums.size();
    for (int i = 0; i < n; ++i) left = max(left, nums[i]), right += nums[i];

    int mid, res = 0;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        int there = 0, current = 0;
        for (int i = 0; i < n; ++i) {
            if (current + nums[i] <= mid) current += nums[i];
            else there++, current = nums[i];
        }
        there++;

        if (there <= m) right = mid - 1, res = mid;
        else left = mid + 1;
    }
    return res;
}
};
