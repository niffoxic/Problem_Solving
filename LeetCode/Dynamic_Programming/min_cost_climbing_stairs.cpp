// top bottom dp
int dp1[1001];
int ans(vector<int>& cost, int n){
    if (n <= 0) return 0;
    if (dp1[n] != -1) return dp1[n];
    return dp1[n] = min(cost[n] + ans(cost, n - 1), cost[n - 1] + ans(cost, n - 2));
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    for(int & i : dp1) i = -1;
    return ans(cost, n - 1);
}
