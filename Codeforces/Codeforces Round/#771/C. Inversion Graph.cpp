#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()
#define pb push_back
#define lb lower_bound
#define up upper_bound


const int mod = 1e9 + 7;
const int dp_size = 1e5;
const ll INF = LLONG_MAX;

ll n, m, q, k, l, r, x, y, z, w, h, total;
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;


void solve(int case_no)
{
    cin >> n;
    total = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> st; st.insert(0);
    for(int i = 1; i <= n; i++) st.insert(-i);
    l = n, r = n, m = n;
    for(ll i = n - 1; i >= 0; i--)
    {
        st.erase(-a[i]);
        if (a[i] == r)
        {
            int next_root = -*st.begin();
            if (next_root == m - (l - i)) total++, r = next_root, m = next_root, l = i;
            else r = next_root;
        }
    }
    cout << total << "\n";
}

int main()
{

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
