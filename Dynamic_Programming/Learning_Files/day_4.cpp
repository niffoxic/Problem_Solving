// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll = long long;
using str = string;
using db = long double;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vpd = vector<pdb>;
using umi = unordered_map<int, int>;

#define print(x) cout << x << nn;
#define all(x) x.begin(), x.end()

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define nn "\n"
#define Yes "Yes"
#define YES "YES"
#define yes "yes"
#define no "no"
#define No "No"
#define NO "NO"
#define def auto

// ****************************************************************************************

const int mod = 1e9 + 7;

// Minimum sum Partition

// Recursion

int minDifferenceSolve(int arr[], int n, int sum, int current) {
    if (n == 0) return abs(abs(current - sum) - current);
    return min(minDifferenceSolve(arr, n - 1, sum, current + arr[n - 1]),
               minDifferenceSolve(arr, n - 1, sum, current));
}

int minDifference(int const arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 1; i <= sum; i++) dp[0][i] = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0){
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    int diff = INT_MAX;

    for(int i = sum/2; i >= 0; i--){
        if (dp[n][i])
            return diff = sum - 2 * i;
    }
    return sum;
}

// Count the subsets with a given difference k

// Recursion
int subset_with_k(int arr[], int n, int sum, int k, int total_sum){
    if (n == 0 && abs(abs(total_sum - sum) - sum) == k) return 1;
    if (n == 0) return 0;
    return subset_with_k(arr, n - 1, sum + arr[n - 1], k, total_sum) +
    subset_with_k(arr, n - 1, sum, k, total_sum);
}

// DP
int subset_with_k_diff_dp(int const arr[], int n, int diff){
    int sum = 0; for(int i = 0; i < n; i++) sum += arr[i];
    int target_sum = (sum + diff) / 2;

    int dp[n + 1][target_sum + 1];
    for(int i = 0; i <= target_sum; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if (j - arr[i - 1] >= 0){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}


// Target Sum problem

int findTargetSumWays(vector<int>& arr, int target){

    int sum = 0; for(int i : arr) sum += i;
    int setting = (sum + target) / 2;
    if (sum < target || target < -sum || ((sum + target) & 1)) return 0;
    int dp[arr.size() + 1][setting + 1];

    for(int i = 0; i <= setting; i++) dp[0][i] = 0;
    for(int i = 0; i <= arr.size(); i++) dp[i][0] = 1;

    for(int i = 1; i <= arr.size(); i++){
        for(int j = 0; j <= setting; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0) dp[i][j] += dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[arr.size()][setting];
}

// Unbounded knapsack
int knapSack(int n, int w, int const val[], int const wt[]){
    int dp[n + 1][w + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= w; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            dp[i][j] = dp[i - 1][j];
            if (i >= wt[j - 1]){
                dp[i][j] = max(dp[i][j], dp[i][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][w];
}

// Minimum number of coins
int minCoinsSolve(int const coins[], int m, int n){
    if (n == 0) return 0;
    if (m == 0) return INT_MAX - 1;
    int left = INT_MAX - 1, right = INT_MAX - 1;
    if (n - coins[m - 1] >= 0) left = 1 + minCoinsSolve(coins, m - 1, n - coins[m - 1]);
    right = minCoinsSolve(coins, m - 1, n);
    return min(left, right);
}

int minCoins(int const coins[], int m, int n){
    int dp[n + 1]; for(int i = 0 ; i <= n; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if (i - coins[j] >= 0){
                int res = dp[i - coins[j]];
                if (res != INT_MAX){
                    dp[i] = min(dp[i], res + 1);
                }
            }
        }
    }
    return dp[n] == INT_MAX?-1:dp[n];
}


int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n = 11, m = 4;
        int coins[] = {9, 6, 5, 1};
        print(minCoins(coins, m, n))
    }
    return 0;
}
