#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using str = string;
using ld = double;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vld = vector<ld>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpld = vector<pld>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;

using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vvld = vector<vld>;

#define print(x) cout << (x) << nn;
#define all(x) x.begin(), x.end()
#define pf push_front
#define ar array
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

// ****************************************************************************************
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v);

template<typename T>
ostream &operator<<(ostream &os, const set<T> &v);

template<typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v);

template<typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v);

template<typename T>
inline istream &operator>>(istream &in, vector<T> &a);
// ****************************************************************************************

const int mod = 1e9 + 7;
const int dp_size = 1e5;
const ll INF = LLONG_MAX;



void solve(int case_no) {
    ll n; cin >> n;
    ll res = 0, total = n * (n + 1) / 2;
    if (total % 2)
        print(res)
    else{
        double fq, q = (sqrt((4 * total) + 1) - 1) / 2;
        fq = floor(q);
        if (q == fq)
            res = (fq * (fq - 1) / 2) + ((n - fq) * (n - fq - 1) / 2);
        res += n - fq;
        print(res)
    }

}

int main() {

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
