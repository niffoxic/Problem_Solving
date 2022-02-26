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

ll n, m, q, k, l, r, x, y, z, c, d, ti, a, b;
const ll template_array_size = 1e7 + 1;
ll arr[template_array_size];
ll brr[template_array_size];
ll crr[template_array_size];

ll Arr[1001][1001];
ll Brr[1001][1001];
ll Crr[1001][1001];
string s, t;

void fill(){
    for(int i = 0; i < template_array_size; i++) arr[i] = i;
    for(int i = 2; i < template_array_size; i++)
        if (arr[i] == i)
            for(int j = i; j < template_array_size; j += i)
                arr[j] -= arr[j] / i;
    for(int i = 1; i < template_array_size; i++)
        brr[i] = arr[i] + brr[i - 1];
}

void solve(int case_no) {
    cin >> a >> b;
    cout << brr[b] - brr[a - 1] << "\n";
}

int main() {

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill();
    int test_case = 1;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
