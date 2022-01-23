class Solution{
public:	
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int> res;
        for(int i = 0; i < n; i++) res.push(arr[i]);
        vector<int> ans; int i = 0;
        while (i++ < k && !res.empty()) ans.push_back(res.top()), res.pop();
        return ans;
    }
};
