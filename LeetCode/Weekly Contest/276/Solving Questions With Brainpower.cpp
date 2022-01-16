
class Solution {
public:

    long long dp[100001];
    long long solve(vector<vector<int>>& q, int index){
        if (index >= q.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        return dp[index] = max(solve(q, index + 1),
                               solve(q, index + q[index][1] + 1) + q[index][0]);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        for(long long & i : dp) i = -1;
        return solve(questions, 0);
    }
};
