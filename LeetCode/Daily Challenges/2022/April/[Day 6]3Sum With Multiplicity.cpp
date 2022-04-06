class Solution {
public:
    int threeSumMulti(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        long long mod = 1e9 + 7, sum;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                sum = nums[l] + nums[i] + nums[r];
                if (sum == target) {
                    int count1 = 1, count2 = 1;
                    while (l < r && nums[l] == nums[l + 1]) l++, count1++;
                    while (l < r && nums[r] == nums[r - 1]) r--, count2++;
                    if (l == r) res = (res % mod + (count1 % mod * (count1 - 1) % mod) / 2) % mod;
                    else res = (res % mod + (count1 % mod * count2 % mod) % mod) % mod;
                    l++, r--;
                } else {
                    if (sum > target) r--;
                    else l++;
                }
            }
        }
        return res;
    }
};
