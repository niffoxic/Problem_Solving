



//                                                             Dynamic programming - Day 1  <3 <3 ( gulabi dil )






// #include <bits/stdc++.h
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
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T> ostream &operator<<(ostream &os, const set<T> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v);
template <typename T> inline istream &operator>>(istream &in, vector<T> &a);
// ****************************************************************************************

const int mod = 1e9+7;


// Introduction to DP
ull fib(ull n, ull dp[]){
    if (n == 1 || n == 2) return 1;
    if (n == 0) return 0;
    if (dp[n]) return dp[n];
    ull ans = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n] = ans;
}

// Minimum steps to One
void bottom_top_dp(int n){
    int dp[n];
    dp[1] = 0;
    for(int i = 2;i <= n;i++){
        if (i % 2 == 0 && i % 3 == 0){
            dp[i] = min(dp[i/2], min(dp[i/3], dp[i - 1])) + 1;
        }else if (i % 2 == 0) dp[i] = min(dp[i/2], dp[i - 1]) + 1;
        else if (i % 3 == 0) dp[i] = min(dp[i/3], dp[i - 1]) + 1;
        else dp[i] = dp[i - 1] + 1;
    }
    cout << dp[n] << nn;
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}

int top_bottom_dp(int n, int dp[]){
    if (n == 1) return 0;
    if (dp[n]) return dp[n];
    int o1 = INT_MAX, o2 = INT_MAX, o3 = INT_MAX;
    if (n % 2 == 0) o2 = top_bottom_dp(n / 2, dp) + 1;
    if (n % 3 == 0) o3 = top_bottom_dp(n / 3, dp) + 1;
    o1 = top_bottom_dp(n - 1, dp) + 1;
    int ans = min(min(o1, o2), o3);
    return dp[n] = ans;
}

// Min Coin Change
int coins(int c[], int t, int n, int dp[]){
    if(n == 0) return 0;
    if (dp[n]) return dp[n];
    int ans = INT_MAX;
    for(int i = 0; i < t; i++){
        if (n - c[i] >= 0){
            int curr = coins(c, t, n - c[i], dp);
            ans = min(ans, curr + 1);
        }
    }
    return dp[n] = ans;
}

int coins_here(int const c[], int total, int n){
    int dp[1000] = {0};
    for(int i = 1; i <= n; i++){
        int res = INT_MAX;
        for(int j = 0; j < total; j++){
            if (i - c[j] >= 0){
                res = min(res, dp[i - c[j]]);
            }
        }
        dp[i] = res + 1;
    }
    return dp[n];
}

// MAX WINES PROBLEM
int top_bottom_wines(int prices[], int day, int i, int j, int dp[100][100]){
    if (i > j) return 0;
    if (dp[i][j]) return dp[i][j];
    int left = prices[i] * day + top_bottom_wines(prices, day + 1, i + 1, j, dp);
    int right = prices[j] * day + top_bottom_wines(prices, day + 1, i, j - 1, dp);
    int res = max(left, right);
    return dp[i][j] = res;
}
// Incomplete one ------------------------------------------------------------->
//int bottom_top(int const prices[], int n, int dp[n][n]){
//    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if (i > j) dp[i][j] = 0;
//    for(int i = 0; i < n; i++){
//        dp[i][i] = n * prices[i];
//    }
//    int j = 1;
//    while (j < n){
//        for(int i = 0; i < n; i++){
//
//        }
//    }
//
//}

// Maximum Subarray sum
int top_kadane(int const arr[], int n){
    int dp[n]; dp[0] = arr[0] > 0? arr[0]: 0;
    int res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0) dp[i] = 0;
        res = max(dp[i], res);
    }
    return res;
}

// Optimised
long long maxSubArray(vector<int>& nums) {
    long long total = INT_MIN;
    long long res = INT_MIN;
    for(int num : nums){
        total = num > total + num? num: total + num;
        res = res > total? res: total;
    }

    return res;
}


// Ladder Optimised Approach by niffoxic;
int ladder_optimised(int n, int k, int dp[]){
    dp[0] = 1;
    int prev = 1;
    int all = 1;
    for(int i = 1; i < k; i++){
        dp[i] = dp[i - 1] + prev;
        prev = dp[i];
        all += prev;
    }
    for(int i = k; i < n; i++){
        dp[i] = all;
        all += dp[i] - dp[i - k];
    }
    for(int i = 0; i < n; i++) cout << dp[i] << " ";
    return dp[n - 1];
}

// Rod Cutting problem
int rod_top_bottom(int prices[], int t, int n, int dp[], int index){
    if (n == 0) return 0;
    if (dp[n]) return dp[n];
    int res = INT_MIN;
    for(int i = index; i < t; i++){
        if (n - i - 1 >= 0){
            int current = prices[i] + rod_top_bottom(prices, t, n - i - 1, dp, i);
            res = max(res, current);
        }
    }
    return dp[n] = res;
}

int rod_bottom_top(int const prices[], int t, int n, int dp[]){
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int ans = INT_MIN;
        for(int j = 0; j < i; j++){
            int current = prices[j] + dp[i - j - 1];
            ans = max(ans, current);
        }
        dp[i] = ans;
    }
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << nn;
    return dp[n];
}

// longest common subsequence
int top_down_lcs(str s1, str s2, int n1, int n2, int i, int j, vector<vi> &dp, int arr[][10]){
    if (n1 == i || n2 == j) return arr[i][j] = 1;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]){
        cout << s1[i];
        return dp[i][j] = 1 + top_down_lcs(s1, s2, n1, n2, i + 1, j + 1, dp, arr);
    }

    int a = top_down_lcs(s1, s2, n1, n2, i  + 1, j, dp, arr);
    int b = top_down_lcs(s1, s2, n1, n2, i, j + 1, dp, arr);

    return dp[i][j] = max(a, b);
}

// top bottom DP
int solve(int n, int dp[]){
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dp[n]) return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs1(int n){
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++) dp[i] = 0;
    int res = solve(n, dp);
    return res;
}

// Bottom UP DP
int climbStairs2(int n){
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++) dp[i] = 0;
    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Optimised Version
int climbStairs3(int n){
    int prev = 1, current = 1;
    for(int i = 2; i <= n; i++){
        int temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}

vector<vector<int>> generate(int n) {
    vector<vector<int>> dp;
    dp.push_back({1});
    for(int i = 1; i <= n; i++){
        vector<int> current(i + 1, 0);
        for(int j = 0; j < i; j++){
            if (j - 1 < 0) current[j] = dp[i - 1][j];
            else{
                current[j] = dp[i - 1][j - 1] + current[j - 1];
            }
        }
        dp.pb(current);
    }
    return dp;
}

int maxProfit(vector<int>& prices){
    int n = prices.size();
    int dp[n]; dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + (prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0);
    }
    return dp[n - 1];
}

// optimised
int maxProfit2(vector<int>& prices){
    int n = prices.size();
    int res = 0;
    for(int i = 1; i < n; i++){
        res += max(0, prices[i] - prices[i - 1]);
    }
    return res;
}

vector<int> countBits(int n) {
    vector<int> res;
    for(int i = 0; i <= n; i++){
        int current = 0;
        int temp = i;
        while(temp){
            current++;
            temp >>= (temp & -temp);
        }
        res.push_back(current);
    }
    return res;
}


int dp[10000][100];

int solving(string s1, string s2, int n1, int n2, int i, int j){
    if (i == n1 || j == n2) return 0;

    if (dp[j][i] != -1) return dp[j][i];

    if (s1[i] == s2[j]){
        return dp[j][i] = 1 + solving(s1, s2, n1, n2, i + 1, j + 1);
    }

    int op1 = solving(s1, s2, n1, n2, i + 1, j);
    int op2 = solving(s1, s2, n1, n2, i, j + 1);

    return dp[j][i] = max(op1, op2);
}

bool isSubsequence(string s1, string s2) {
    for(auto & i : dp)
        for(int & j : i)
            j = -1;
    int n1 = s1.size();
    int n2 = s2.size();
    int res = solving(s1, s2, n1, n2, 0, 0);
    if (res == n1) return true;
    return false;
}

int dp1[1001];
int ans(vector<int>& cost, int n){
    if (n <= 0){
        return 0;
    }
    if (dp1[n] != -1) return dp1[n];
    int res = 10000;
    int op1 = cost[n] + ans(cost, n - 1);
    int op2 = cost[n - 1] + ans(cost, n - 2);
    res = min(op1, op2);
    return dp1[n] = res;
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    for(int & i : dp1) i = -1;
    return ans(cost, n - 1);
}

int natural[] = {-1, -1, 5, -1, -1, 2, 9, -1, -1, 6};
int rotatedDigits(int n){
    int res = 0;
    for(int i = 2; i <= n; i++){
        bool adding = true;
        int temp = i;
        while (temp){
            if (natural[temp % 10] == -1){
                adding = false;
                break;
            }
            temp /= 10;
        }
        if (adding) res++;
    }
    return res;
}


int main()
{
//  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n; cin >> n;
        // done
    }
    return 0;
}
