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

// Optimal Strategy For a Game
ll maximumAmountSolve(int arr[], int n, int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int left = arr[i] + min(maximumAmountSolve(arr, n, i + 2, j), maximumAmountSolve(arr, n, i + 1, j - 1));
    int right = arr[j] + min(maximumAmountSolve(arr, n, i, j - 2), maximumAmountSolve(arr, n, i + 1, j - 1));

    return dp[i][j] = max(left, right);
}

ll maximumAmount1(int arr[], int n) {
    for (auto& i : dp) for (auto &j : i) j = -1;
    return maximumAmountSolve(arr, n, 0, n - 1);
}

// Subset Sum Problem
int dp2[101][10001];
bool isSubsetSumSolve(int n, int arr[], int sum, int index) {
    if (sum == 0) {
        return true;
    }
    if (index == n || sum < 0) return false;
    return (isSubsetSumSolve(n, arr, sum - arr[index], index + 1) || isSubsetSumSolve(n, arr, sum, index + 1));
}

int perfectSum(int arr[], int n, int sum) {

    int dp3[101][101];
    for (int i = 0; i <= n; i++) dp3[i][0] = 1;
    for (int i = 1; i <= sum; i++) dp3[0][i] = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                dp3[i][j] = (dp3[i - 1][j - arr[i - 1]] + dp3[i - 1][j]) % 1000000007;
            }
            else {
                dp3[i][j] = dp3[i - 1][j];
            }
        }
    }
    return dp3[n][sum];
}

// Partition Equal Subset Sum

// Recursion
bool equalPartitionSolve(int n, int arr[], int sum, int current) {
    if (n == 0 || sum < 0 || current > sum) return false;
    if (sum == current) return true;

    return equalPartitionSolve(n - 1, arr, sum - arr[n - 1], current + arr[n - 1]) ||
        equalPartitionSolve(n - 1, arr, sum, current);
}


bool dp3[101][10001];

bool equalPartition(int n, int arr[])
{
    int sum = 0; for (int i = 0; i < n; i++) sum += arr[i];
    if (sum & 1) return false;
    sum /= 2;

    for (int i = 0; i < sum + 1; i++) dp3[0][i] = false;
    for (int i = 0; i < n + 1; i++) dp3[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                dp3[i][j] = dp3[i - 1][j - arr[i - 1]] || dp3[i - 1][j];
            }
            else {
                dp3[i][j] = dp3[i - 1][j];
            }
        }
    }
    return dp3[n][sum];
}

// Perfect Sum Problem
int perfectSumSolve(int arr[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0 or sum < 0) return 0;

    return perfectSumSolve(arr, n - 1, sum - arr[n - 1]) + perfectSumSolve(arr, n - 1, sum);
}
int perfectSum(int arr[], int n, int sum) {
    int dp3[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++) dp3[0][i] = 0;
    for (int i = 0; i <= n; i++) dp3[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j  >= arr[i - 1]) {
                dp3[i][j] = dp3[i - 1][j - arr[i - 1]] + dp3[i - 1][j];
            }
            else {
                dp3[i][j] = dp3[i - 1][j];
            }
        }
    }
    return dp3[n][sum];
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
        int n = 6;
        int arr[] = { 2, 3, 5, 6, 8, 10 };
        int sum = 10;
    }
    return 0;
}
