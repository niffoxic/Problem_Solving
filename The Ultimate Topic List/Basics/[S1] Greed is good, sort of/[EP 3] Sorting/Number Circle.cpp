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
    cin >> n;
    map<ll, ll, greater<>> mp;
    for(int i = 0; i < n; i++) cin >> arr[i], mp[arr[i]]++;
    sort(arr, arr + n);
    if (arr[n - 1] >= arr[n - 2] + arr[n - 3]){
        cout << "NO"; return;
    }
    cout << "YES\n";
    l = 0, r = n - 1, x = 0;
    for(auto i: mp){
        for(int j = 0; j < i.second; j++){
            if (!x) arr[l] = i.first, l++;
            else arr[r] = i.first, r--;
        }
        x ^= 1;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
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
