class KthLargest {
private:
    priority_queue<int, vector<int>, greater<>> data;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        for(auto i: nums){
            data.push(i);
            if (data.size() > k) data.pop();
        }
        kth = k;
    }

    int add(int val) {
        if (kth > data.size())
            data.push(val);
        else{
            if (val > data.top()){
                data.pop();
                data.push(val);
            }
        }
        return data.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
