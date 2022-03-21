#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
     // 1st Solution
    int recursion(string& s1, string& s2, int n, int m, vector<vector<int>>& dp){
        if (!n || !m) return n? n: m;
        if (dp[n][m] != -1) return dp[n][m];
        if (s1[n - 1] == s2[m - 1]) return recursion(s1, s2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min({
            recursion(s1, s2, n - 1, m, dp), // deleting from s1
            recursion(s1, s2, n, m - 1, dp), // adding to s1,
            recursion(s1, s2, n - 1, m - 1, dp) // replacing current index
        });
    }

    int minDistance1(string& word1, string& word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return recursion(word1, word2, n, m, dp);
    }
    // 2nd solution
    int minDistance(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        int dp[n + 1][m + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if (!i && !j) dp[i][j] = 0;
                else if (!i) dp[i][j] = j;
                else if (!j) dp[i][j] = i;
                else{
                    if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
};
