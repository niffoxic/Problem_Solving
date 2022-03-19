#include <bits/stdc++.h>

using namespace std;

using umi = unordered_map<int, int>;
using ums = unordered_map<int, stack<int>>;

class FreqStack {
    umi mp;
    ums st;
    int res;
public:
    FreqStack() {
        res = 0;
    }
    void push(int val) {
        mp[val]++;
        st[mp[val]].push(val);
        res = max(res, mp[val]);
    }

    int pop() {
        if (res == 0) return -1;
        stack<int> &curr = st[res];
        int ans = curr.top();
        curr.pop();
        mp[ans]--;
        if (curr.empty()) res--;
        return ans;
    }
};
