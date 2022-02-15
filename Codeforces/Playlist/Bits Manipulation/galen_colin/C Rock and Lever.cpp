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
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
void solve(int case_no){
    cin >> n;
    vector<ll> most(32, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll msb = 63 - __builtin_clzll(a[i]); // get the leading zeros
        most[msb]++;
    }
    ll res = 0;
    for(int i = 0; i < 32; i++) res += (most[i] * (most[i] - 1)) / 2;
    cout << res << "\n";
}
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);
 
    return 0;
}
