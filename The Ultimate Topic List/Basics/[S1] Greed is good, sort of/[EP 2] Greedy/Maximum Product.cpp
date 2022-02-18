#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()
#define mp make_pair
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
string s, t;

void solve(int case_no)
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], m = max(m, arr[i]);
    sort(arr, arr + n);
    x = arr[0] * arr[1] * arr[2] * arr[3] * arr[n - 1];
    y = arr[0] * arr[1] * arr[n - 3] * arr[n - 2] * arr[n - 1];
    z = arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4] * arr[n - 5];
    cout << max(x, max(y, z)) << "\n";
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
