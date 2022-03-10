#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        int dp[n]; for(int i = 0; i < n; i++) dp[i] = 0;
        if (s[n - 1] == '0') dp[n - 1] = 0;
        else dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') dp[i] = dp[i + 1];
            if (s[i] == '1') dp[i] = min(2 + dp[i + 1], n - i);
        }
        int ans = dp[0];
        for (int i = 0; i < n - 1; i++) ans = min(ans, i + 1 + dp[i + 1]);
        ans = min(ans, n);
        return ans;
    }
};
