class Solution {
public:
int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> res(stones.begin(), stones.end());
    while (res.size() > 1) {
        int current = res.top();
        res.pop();
        int x = res.top();
        res.pop();
        if (x != current) res.push(current - x);
    }
    return res.empty() ? 0 : res.top();
}

};
