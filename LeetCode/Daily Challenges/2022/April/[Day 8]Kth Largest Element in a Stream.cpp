class KthLargest {
public:

    priority_queue<int, vector<int>, greater<>> q;
    int K;
    KthLargest(int k, vector<int> &nums) {
        K = k;
        for (int x : nums) {
            q.push(x);
            if (q.size() > k) q.pop();
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }
};
