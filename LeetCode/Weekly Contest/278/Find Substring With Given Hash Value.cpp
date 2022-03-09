#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int target) {
        long hv = 0, n = s.size(), pVal = 1;
        int index = -1;
        string r(rbegin(s), rend(s));
        for (int i = 0; i < n; ++i) {
            if (i < k) pVal = pVal * p % mod;
            hv = (hv * p + (r[i] - 'a' + 1)) % mod;
            if (i - k >= 0) hv = (hv - (r[i - k] - 'a' + 1) * pVal % mod + mod) % mod;
            if (hv == target) index = i;
        }
        return index == -1? "": s.substr(n - index - 1, k);
    }
};
