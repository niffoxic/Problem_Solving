#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()
#define pb push_back
#define lb lower_bound
#define up upper_bound


const int mod = 1e9 + 7;
const int dp_size = 1e5;
const ll INF = LLONG_MAX;

ull n, m, q, k, l, r, x, y, z, w, h;
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

bool canFit()
{
    return (x / w) * (x / h) >= n;
}

void solve(int case_no){
    cin >> w >> h >> n;
    l = 0, r = max(w, h) * n;
    ll res = -1;
    while (l <= r){
        x = l + ((r - l) >> 1ULL);
        if (canFit()) res = x, r = x - 1;
        else l = x + 1;
    }
    cout << res;
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
    // cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}