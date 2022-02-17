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
    cin >> n >> k;
    vector<int> res(80, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        x = a[i], y = 0;
        while (x) x &= (x - 1), y++;
        res[y]++;
    }
    int j = 79, ans = 0;
    while (k)
    {
        if (res[j] >= k) ans += k * j, k = 0;
        else ans += res[j] * j, k -= res[j], j--;
    }
    cout << ans << "\n";
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
