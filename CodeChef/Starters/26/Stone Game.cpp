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
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<>());
  // 3 Two Pointers xD
    string res = s + t; int i = 0, j = 2 * n - 1;
    int sleft = 0, sright = n - 1, tleft = 0, tright = n - 1;
    while (i < j)
    {
        if (s[sleft] < t[tleft]) res[i] = s[sleft], sleft++, i++;
        else res[j] = s[sright], sright--, j--;

        if (t[tleft] > s[sleft]) res[i] = t[tleft], tleft++, i++;
        else res[j] = t[tright], tright--, j--;
    }
    cout << res << "\n";
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
