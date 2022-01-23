class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>>& arr, int k)
    {
        // Same complexity anyway
        priority_queue<int, vector<int>, greater<>> q; vector<int> res;
        for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) q.push(arr[i][j]);
        while (!q.empty()) res.push_back(q.top()), q.pop();
        return res;
    }
};
