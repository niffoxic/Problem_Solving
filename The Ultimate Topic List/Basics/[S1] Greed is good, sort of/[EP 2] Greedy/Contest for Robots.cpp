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
#include <string.h>
 
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
        int arr[n];
 
        for(int i = 0; i < n; i++) cin >> arr[i];
        int total = 0, left = 0;
        for(int i = 0; i < n; i++){
            int b; cin >> b;
            if(b != arr[i]){
                left += b;
                total += arr[i];
            }
        }
 
        if (total == 0 || left == n)
            cout << -1 << nn;
        else
            cout << left / total + 1;
 
    }
 
    return 0;
}
