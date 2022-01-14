#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll poly(ll a, ll b, ll c, ll x){
    return a * (x * x) + b * x + c;
}

void solve(int case_no){
    ll a, b, c, k; cin >> a >> b >> c >> k;
    ll left = 0, right = 1e10;
    ll res = INT_MAX;
    while(left <= right){
        ll mid = left + (right - left) / 2;
        ull current = poly(a, b, c, mid);
        if (current == k){
            res = mid;
            break;
        }else if (current > k){
            right = mid - 1;
            res = mid;
        }
        else left = mid + 1;
    }
    cout << res << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
