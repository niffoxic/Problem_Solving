#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int inf = 1e9, n = nums.size(), res = 0;
        vector<int> dp(n + 1, 1e9);
        dp[0] = INT_MIN;
        for(int i = 0; i < n; i++){
            int up = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (dp[up - 1] < nums[i] && nums[i] < dp[up])
                dp[up] = nums[i], res = max(res, up);
        }
        return res;
    }
};

int main(){
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution ob;
    cout << ob.lengthOfLIS(nums);
}
