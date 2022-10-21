class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++) pq.push(make_pair(arr[i], i));
        vector<int> res; res.push_back(pq.top().first);
        for(int i = k; i < n; i++){
            pq.push(make_pair(arr[i], i));
            // cout << pq.top().first << " " << pq.top().second << "\n";
            while (pq.top().second < i - k + 1) pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};
