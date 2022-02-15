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
    unordered_map<ull, ull> mp;
    ull res = 0;
    while (n--)
    {
        cin >> s;
        ull mask = 0;
        for(auto i: s){
            ull bit = i - 'a';
            mask ^= (1ULL << bit);
        }
        res += mp[mask]; // Even case
        for(ull i = 0; i < 26; i++)
        {
            mask ^= (1ULL << i);
            res += mp[mask]; // odd case
            mask ^= (1ULL << i);
        }
        mp[mask]++;
    }
    cout << res;
}
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int test_case = 1;
    // cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);
 
    return 0;
}
