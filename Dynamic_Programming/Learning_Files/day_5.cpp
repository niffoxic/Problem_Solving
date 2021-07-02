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


int lcsSolve(int x, int y, string s1, string s2)
{
    int dp[1001][1001];
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0 || y == 0) return 0;
    if (s1[x - 1] == s2[y - 1]) return dp[x][y] = 1 + lcsSolve(x - 1, y - 1, s1, s2);
    int left = lcsSolve(x - 1, y, s1, s2);
    int right = lcsSolve(x, y - 1, s1, s2);

    return dp[x][y] = max(left, right);
}
int lcs(int x, int y, string s1, string s2){
    int dp[1001][1001];
    for(int i = 0; i <= x; i++) dp[i][0] = 0;
    for(int i = 0; i <= y; i++) dp[0][i] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}

// Longest Common Substring
int longestCommonSubstr(string s1, string s2, int n, int m){
    int dp[1001][1001];
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    int res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[j - 1] == s2[i - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(dp[i][j], res);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

// Printing All LCS sequences
void all_longest_common_subsequences(string s1, string s2, int n, int m){
    int dp[1001][1001];
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (s1[j - 1] == s2[i - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << " ";
        }cout << nn;
    }
    print(nn)
    int i = m, j = n;
    string ans;
    while(i > 0 && j > 0){
        cout << dp[i][j] << " ";
        if (s2[i - 1] == s1[j - 1]){
            ans.push_back(s1[j - 1]);
            i--, j--;
        }else{
            if (dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }

    }
    print("")
    cout << ans << nn;
}

int shortestCommonSupersequence(string x, string y, int m, int n)
{
    int dp[1001][1001];
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return 0;
}

// Minimum number of deletions and insertions
int minOperations(string s1, string s2){
    int dp[1001][1001];
    int n = s1.size(), m = s2.size();

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int res = n - dp[n][m];
    res += m - dp[n][m];
    return res;
}

// Longest Palindromic Subsequence
int longestPalinSubseq (string s1)
{
    int dp[1001][1001];
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    for(int i = 0; i <= n; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

// Minimum Deletions
int minimumNumberOfDeletions(string s1) {
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.length();
    int dp[n + 1][n + 1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return n - dp[n][n];
}

// Shortest Common SuperSequence
string shortestCommonSupersequence(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j<= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int res[256] = {0};
    for(int k = 0; k < n; k++) res[s1[k]]++;
    for(int k = 0; k < m; k++) res[s2[k]]++;
    string lcs{};
    int i = n, j = m;
    while (i && j){
        if (s1[i - 1] == s2[j - 1]){
            lcs.push_back(s1[i - 1]);
            i--, j--;
        }else{
            if(dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }
    string ans = "" ;
    reverse(lcs.begin(), lcs.end());
    cout << "lcs : " << lcs << endl;
    i = 0 , j = 0;
    cout <<"s " << s1 << " " << s2 << endl;
    for(char lc : lcs) {
        while(i < n && s1[i] != lc) {
            ans += s1[i]; ++i;
        }
        while(j < m && s2[j] != lc) {
            ans += s2[j]; ++j;
        }
        ans += lc;
        ++i, ++j;
    }
    ans += s1.substr(i);
    ans += s2.substr(j);

    return ans;
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
        print(shortestCommonSupersequence("abac", "cab"))
    }
    return 0;
}
