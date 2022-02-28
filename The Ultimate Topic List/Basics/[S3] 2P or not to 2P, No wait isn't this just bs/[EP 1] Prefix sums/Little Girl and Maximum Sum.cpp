#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()
#define mkp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound


const int mod = 1e9 + 7;
const int dp_size = 1e5;
const ll INF = LLONG_MAX;

ll n, m, q, k, l, r, x, y, z, c;
const ll template_array_size = 1e6;
ll arr[template_array_size];
ll brr[template_array_size];
ll crr[template_array_size];

ll Arr[1001][1001];
ll Brr[1001][1001];
ll Crr[1001][1001];

string s, t;

void solve(int case_no)
{
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    while (q--){
        cin >> l >> r;
        l--, r--;
        if (r < n - 1) brr[r + 1]--;
        brr[l]++;
    }
    int current = 0;
    for(int i = 0; i < n; i++){
        current += brr[i];
        crr[i] = current;
    }
    sort(arr, arr + n);
    sort(crr, crr + n);
    ll res = 0;
    for(int i = 0; i < n; i++) res += arr[i] * crr[i];
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
    // cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
