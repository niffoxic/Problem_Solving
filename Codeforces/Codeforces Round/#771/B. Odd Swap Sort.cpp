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

ll n, m, q, k, l, r, x, y, z, w, h;
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;


void solve(int case_no)
{
    cin >> n;
    vector<int> odd, even, todd, teven;
    for(int i = 0; i < n; i++){
        cin >> q;
        if (q & 1) odd.pb(q);
        else even.pb(q);
    }
    todd = odd, teven = even;
    sort(all(todd)), sort(all(teven));
    bool res = true;
    for(int i = 0; i < odd.size() && res; i++){
        if (todd[i] != odd[i]) res = false;
    }
    for(int i = 0; i < even.size() && res; i++)
        if (teven[i] != even[i]) res = false;
    cout << (res?"Yes": "No") << "\n";
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
