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

ld n, m, q, k, l, r, x, y, z, w, h, res;
const ll template_array_size = 1e6;
ld a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

bool itCan(){
    int canCut = 0;
    for(int i = 0; i < n; i++)
        canCut += (a[i] / x);
    return canCut >= k;
}

void solve(int case_no){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i], r = max(r, a[i]);
    for(int i = 0; i < 100; i++){
        x = l + (r  - l) / 2;
        if (itCan())
            l = x;
        else r = x;
    }
    cout << setprecision(10) << l;
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
