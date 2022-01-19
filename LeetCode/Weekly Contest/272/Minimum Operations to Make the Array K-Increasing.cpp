class Solution {
public:

    int helper(vector<int>& arr){
        int n = arr.size();
        vector<int>dp;
        dp.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            if (dp.back() <= arr[i])
                dp.push_back(arr[i]);
            else
                dp[upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin()] = arr[i];
        }
        return dp.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int res = 0, n = arr.size();
        for(int i = 0; i < k; i++){
            vector<int> vec;
            for(int j = i; j < n; j+=k)
                vec.push_back(arr[j]);
            res += (int)vec.size() - helper(vec);
        }
        return res;
    }
};
