#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minimumRemoval(vector<int> &beans) {
        if (beans.size() == 1) return 0;
        sort(beans.begin(), beans.end());
        using ll = long long;
        ll res, previous = 0, sum = 0, n = beans.size();
        for (auto b:beans) sum += b;
        res = sum;
        for (int i = 0; i < n; i++) {
            if (i != 0) sum -= beans[i - 1], previous += beans[i - 1];
            ll actual = beans[i] * (n - i);
            ll removed = sum - actual + previous;
            res = min(res, removed);
        }
        return res;
    }
};
