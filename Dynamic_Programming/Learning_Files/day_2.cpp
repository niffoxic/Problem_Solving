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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template <typename T> ostream& operator<<(ostream& os, const set<T>& v);
template <typename T, typename S> ostream& operator<<(ostream& os, const map<T, S>& v);
template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v);
template <typename T> inline istream& operator>>(istream& in, vector<T>& a);
// ****************************************************************************************

const int mod = 1e9 + 7;



long long dp[1001][1001];

long long int rcount(int const coins[], int m, int n) {
    if (n == 0) return 1; if (m == 0) return 0;
    if (dp[n][m]) return dp[n][m];
    long long res = rcount(coins, m - 1, n);
    if (n - coins[m - 1] >= 0) {
        res += rcount(coins, m, n - coins[m - 1]);
    }
    return dp[n][m] = res;
}

long long int count(int c[], int m, int n) {
    for (auto& i : dp) for (long long& j : i) j = 0;
    return rcount(c, m, n);
}

// bottom top

long long count1(int const coins[], int m, int n) {
    for (auto& i : dp) for (long long& j : i) j = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i - coins[j - 1] >= 0) {
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[n][m];
}

int dp3[101][101];
int solve_ed(str s1, int n1, str s2, int n2) {
    if (n1 == 0) return n2; if (n2 == 0) return n1;
    if (dp3[n1][n2] != -1) return dp3[n1][n2];

    if (s1[n1 - 1] == s2[n2 - 1]) return solve_ed(s1, n1 - 1, s2, n2 - 1);
    return dp3[n1][n2] = 1 + min(solve_ed(s1, n1 - 1, s2, n2), min(solve_ed(s1, n1, s2, n2 - 1), solve_ed(s1, n1 - 1, s2, n2 - 1)));
}

int edit_distance(str s1, str s2) {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dp3[i][j] = -1;
        }
    }
    return solve_ed(s1, s1.size(), s2, s2.size());
}

int edit_distance_ut(string s1, string s2) {
    int dp4[101][101];
    int n = s1.size(), m = s2.size();
    for (int i = 0; i <= m; i++) dp4[0][i] = i;
    for (int i = 0; i <= n; i++) dp4[i][0] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp4[i][j] = dp4[i - 1][j - 1];
            }
            else {
                dp4[i][j] = 1 + min(dp4[i - 1][j], min(dp4[i - 1][j - 1], dp4[i][j - 1]));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp4[i][j] << " ";
        }
        print("")
    }
    return dp4[n][m];
}

int longest_increasing_subsequence(int const arr[], int n, int dp5[]) {
    if (n == 0) return 0;
    if (dp5[n] != -1) return dp5[n];
    int left = longest_increasing_subsequence(arr, n - 1, dp5);
    int right = 0;
    if (arr[n - 1] >= arr[n - 2]) {
        right = 1 + longest_increasing_subsequence(arr, n - 1, dp5);
    }
    return dp5[n] = max(left, right);
}

// Maximize the Cut Segments

// Recursion
int maximizeTheCutsSolve(int n, int x, int y, int z) {
    if (n == 0) return 0;
    if (n < 0) return -1;

    
    int left = maximizeTheCutsSolve(n - x, x, y, z);
    int mid = maximizeTheCutsSolve(n - y, x, y, z);
    int right = maximizeTheCutsSolve(n - z, x, y, z);

    int res = max(left, max(mid, right));

    if (res == -1) return res;

    return res + 1;
}

// DP solution
int maximizeTheCuts(int n, int x, int y, int z) {
    int dp6[10001]; dp6[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp6[i] = -1;
        if (i - x >= 0) dp6[i] = max(dp6[i], dp6[i - x]);
        if (i - y >= 0) dp6[i] = max(dp6[i], dp6[i - y]);
        if (i - z >= 0) dp6[i] = max(dp6[i], dp6[i - z]);

        if (dp6[i] != -1) dp6[i] += 1;
    }
    return (dp6[n] == -1) ? 0 : dp6[n];
}


 // Recursive solution ( slow )
int dp7[10000000];
int minJumpsRecursion(int arr[], int n) {
    if (n == 1) return 0;

    if (dp7[n - 1] != -1) return dp7[n - 1];

    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (i + arr[i] >= n - 1) {
            int current = minJumpsRecursion(arr, i + 1);
            if (current != INT_MAX) {
                res = min(res, current + 1);
            }
        }
    }
    return dp7[n - 1] = res;
}

int minJump(int arr[], int n) {
    for (int i = 0; i < 10000000; i++) dp7[i] = -1;
    return minJumpsRecursion(arr, n);
}

// Bottom Up DP
int minJumps(int arr[], int n) {
    int* dp8 = new int[n];
    dp8[0] = 0;
    for (int i = 1; i < n; i++) dp8[i] = INT_MAX;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] + j >= i) {
                if (dp8[j] != INT_MAX) {
                    dp8[i] = min(dp8[i], dp8[j] + 1);
                }
            }
        }
    }
    return dp8[n - 1] == INT_MAX ? -1 : dp8[n - 1];
}

// Optimised

int minJumps2(int arr[], int n) {
    int j = 0, c = 0, cf = 0;
    for (int i = 0; i < n; i++) {
        cf = max(cf, i + arr[i]);
        if (i == c) {
            j++;
            c = cf;
        }
        if (c >= n - 1) break;
    }
    return c < n - 1 ? -1 : j;
}

// Knap Sack recursive solution ( top bottom DP )

int ddp[1001][1001];

int knapSackSolve(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0) return 0;
    if (ddp[W][n] != -1) return ddp[W][n];
    if (wt[n - 1] > W) return knapSackSolve(W, wt, val, n - 1);
    else
        return ddp[W][n] = max(val[n - 1] + knapSackSolve(W - wt[n - 1], wt, val, n - 1), knapSackSolve(W, wt, val, n - 1));
}

int knapSack(int weight, int wtr[], int val[], int n) {
    for (int i = 0; i <= 1000; i++) ddp[0][i] = 0;
    for (int i = 0; i <= 1000; i++) ddp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= weight; j++) {
            if (j < wtr[i - 1]) ddp[i][j] = ddp[i - 1][j];
            else {
                ddp[i][j] = max(val[i - 1] + ddp[i - 1][j - wtr[i - 1]], ddp[i - 1][j]);
            }
        }
    }

    return ddp[n][weight];
}

// Optimal Strategy For a Game Incomplete
ll maximumAmount(int arr[], int n, int i, int j) {
    if (i >= j) return 0;
    int left = arr[i] + maximumAmount(arr, n, i + 1, j - 1);
    int right = arr[j] + maximumAmount(arr, n, i + 1, j - 1);

    return max(left, right);
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
        int n; cin >> n;
        int* arr = new int[n]; for (int i = 0; i < n; i++) cin >> arr[i];
        print(maximumAmount(arr, n, 0, n - 1))
    }
    return 0;
}
