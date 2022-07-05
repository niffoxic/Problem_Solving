#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    map<ll, ll> times;
    int n; cin >> n;
    for(int i = 0, l, r; i < n; i++) cin >> l >> r, times[l]++, times[r + 1]--;
    int res = 0, con = 0;
    for(auto i: times) con += i.second, res = max(res, con);
    return cout << res, 0;
}
