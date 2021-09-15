class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for(auto i: nums) store[i]++;
        priority_queue<pair<int, int>>grt;
        for(auto i: store){
            grt.push(make_pair(i.second, i.first));
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(grt.top().second);
            grt.pop();
        }
        return res;
    }
};
