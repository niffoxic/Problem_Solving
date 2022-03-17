#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto &i: arr) cin >> i;
    ll res = LLONG_MIN, sum = 0;
    for(int i = 0; i < n; i++) sum = max(arr[i], arr[i] + sum), res = max(res, sum);
    return cout << res, 0;
}
