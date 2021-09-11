class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = INT_MAX;
        for(int i = 1; i < arr.size(); i++)
            res = min(res, abs(arr[i - 1] - arr[i]));
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++){
            if (abs(arr[i] - arr[i - 1]) == res)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};
